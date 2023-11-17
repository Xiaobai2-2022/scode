#######################################
# Auto Testing Software for scode     #
# By Zhifan (Xiaobai) Li              #
# Version 0.2.3b                      #
#######################################

#######################################
# Note:                               #
# This script is a shell script,      #
#   meaning that it should only be    #
#   used in Linux environment.        #
#                                     #
# If bash denies the permission,      #
#   use the following command:        #
#   "chmod +x run_test.sh".           #
#                                     #
#######################################

#!/bin/bash

#######################################
# Variables                           #
#######################################

# Colors Defined Here
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
NC='\033[0m'

# File Defined Here
source="../src"
compiled="../bin"
compiled_result="$compiled/scode_test"
compile_err_file="$compiled/cp_res.txt"
test_folder="../tests"
test_in_folder="$test_folder/inputs"
test_out_folder="$test_folder/outputs-expected"
test_out_act_folder="$test_folder/outputs-actual"
test_val_act_folder="$test_folder/valgrind-actual"
manual_test_out="$test_folder/manual_outputs"

#######################################
# Scripts                             #
#######################################

# Clear the console screen
clear

# If clean the compiled file if needed
if [ -f "$compiled.*" ]; then
    make clean
fi

# Checking if the src file can be found complain if not found then terminate
if [ ! -d "$source" ]; then
    echo -e "${RED}Error 901: \n${YELLOW}A build Error is found, missing source folder. \n${RED}Testing terminated...${NC}"
    exit 1
fi

make

# Check for any compilation errors complain if found then terminate
if [ $? -eq 0 ]; then
    
    # Clear the console screen
    clear

    echo -e "${GREEN}Compile Finished...${NC}"
else
    echo -e "${RED}Error 902: \n${YELLOW}A build Error is found, there is an error in compilation, see \"..\\\\compiled\\\\cp_res.txt\" for more info. \n${RED}Testing terminated...${NC}"
    
    # Wait for user input
    read -p "Press Enter to continue..."

    # Clear the console screen
    clear

    exit 1
fi

# # Wait for user input
# read -p "Press Enter to continue..."

# # Clear the console screen
# clear

# Prompt user for testing method
echo -ne "${YELLOW}Proceed with automatic testing(y/N):${NC} " 
read test_with_auto

# Clear the console screen
clear

if [ -d "$test_out_act_folder" ]; then
    rm -r "$test_out_act_folder"
fi
mkdir $test_out_act_folder

if [ -d "$test_out_act_folder" ]; then
    rm -r "$test_out_act_folder"
fi
mkdir $test_out_act_folder

# Test with auto if yes is inputed
if [ "${test_with_auto,,}" = "y" ]; then 

    # Create a variable to check if all tests passed
    test_pass=true
    count_test=0
    count_passed=0

    echo -e "${GREEN}Proceed with auto testing:${NC}"
    echo -e ""
    echo -e ""
    echo -e ""

    # # Wait for user input
    # read -p "Press Enter to continue..."

    # # Clear the console screen
    # clear

    if [ ! -n "$(find "$test_in_folder" -maxdepth 1 -type f -name '*.in')" ]; then
        echo -e "${RED}Error 921: \n${YELLOW}A test Error is found, can not find any test files that ends with \"*.in\". \n${RED}Testing terminated...${NC}"

        # Wait for user input
        read -p "Press Enter to continue..."

        # Clear the console screen
        clear

        make clean

        # Clear the console screen
        clear
        
        exit 1
    fi

    for input_file in "$test_in_folder"/*.in; do

        # Create a variable to check if the current tests passed
        cur_test_pass=true
        
        # Increment test count
        ((++count_test))

        # Extract file without the .in extension
        filename=$(basename "$input_file")
        f_name="${filename%.*}"
        f_in_name="$f_name.in"
        f_out_name="$f_name.out"
        f_val_name="$f_name.val"

        # Generate the .val file for valgrind test result
        # Generate the .out file
        echo -e "${YELLOW}Testing $f_in_name:${CYAN}"
        echo -e "Generating $f_val_name..."
        echo -e "Generating $f_out_name...${NC}"

        valgrind --leak-check=full --error-exitcode=1 --log-file="$test_val_act_folder/$f_val_name" "$compiled_result" < "$input_file" > "$test_out_act_folder/$f_out_name"

        # Check for any compilation errors complain if found then terminate
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}Valgrind test ${f_name} passed!${NC}"
        else
            cur_test_pass=false
            echo -e ""
            echo -e "${RED}Error 922:"
            echo -e "${YELLOW}A valgrind error is found, test \"$f_name\" failed, check log file $test_val_act_folder/$f_val_name for more information."
            echo -e "${RED}Testing will continue...${NC}"
            echo -e ""
        fi

        # Comparing the two .out files
        echo -e "${CYAN}Comparing $f_out_name in outputs and outputs-actual...${NC}"
        if cmp -s "$test_out_act_folder/$f_out_name" "$test_out_folder/$f_out_name"; then
            echo -e "${GREEN}Test ${f_name} passed!${NC}"
            echo -e ""
        else
            cur_test_pass=false
            echo -e ""
            echo -e "${RED}Error 923:"
            echo -e "${YELLOW}A test error is found, test \"$f_name\" failed. Check log file $test_out_act_folder/$f_out_name for more information."
            echo -e "${RED}Testing will continue...${NC}"
            echo -e ""
        fi

        # Check if the current test passed
        if [ "$cur_test_pass" = true ]; then
            ((++count_passed))
        else
            test_pass=false
        fi


    done

# Test with manual setup
else

    echo -e "${GREEN}Proceed with manual testing:${YELLOW}" 
    ./"$compiled_result"
    
    echo -e "${NC}"

fi

# if test pass, proceed to print all tests passed
if [ "$test_pass" = true ]; then
    
    # Clear the console screen
    clear

    echo -e "${GREEN}$count_passed out of $count_test test(s) passed.${NC}"
    echo -e "${GREEN}All tests passed...${NC}"
    echo -e ""

else

    count_failed=$(expr $count_test - $count_passed)
    echo -e "${RED}$count_passed out of $count_test test(s) passed.${NC}"
    echo -e "${RED}$count_failed test(s) failed.${NC}"
    echo -e ""

fi

# Wait for user input
read -p "Press Enter to continue..."

make clean

# Clear the console screen
clear
