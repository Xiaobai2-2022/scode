#include "construct_state.hpp"

bool Ctor_State::sc_bin_to_state(std::string if_name, State &initial_state) {

    initial_state = State{};

    // Address of the instruction
    ulong address{0};

    // Attempt to open input and output file
    std::ifstream fin(if_name);
    
    // Check if the input file failed to open
    if(!fin.is_open()) {

        #ifdef _SVM_PROD_LOG_

        SLog::log("Error constructing RV Binary to State.");
        SLog::log("Error opening the input file: " + if_name + ".");

        #else

        std::cout << SColor::red << "Error constructing rv binary to state." << SColor::nc << std::endl;
        std::cout << SColor::red << "Error opening the input file: " << if_name << "." << SColor::nc << std::endl;

        #endif

        return false;
    }

    std::string cur_line;
    std::getline(fin, cur_line);

    // Check if the risc-v assembly file is of the correct type
    if(!Utility::is_start_with(cur_line, "SCode Binary")) {

        #ifdef _SVM_PROD_LOG_

        SLog::log("Error constructing RV Binary to State.");
        SLog::log("Input file has the wrong type: " + if_name + ".");

        #else

        std::cout << SColor::red << "Error constructing rv binary to state." << SColor::nc << std::endl;
        std::cout << SColor::red << "Input file has the wrong type: " << if_name << "." << SColor::nc << std::endl;

        #endif

        return false;
    }

    unsigned int line_count{};

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        ++line_count;

        std::string word{""};
        std::string temp;

        // Construct the string stream to access all elements on the line
        std::stringstream ssline{cur_line};

        // Read all elements in the string
        while(ssline >> temp) {
            word += temp;
        }

        if(word.length() > 32) {

            #ifdef _SVM_PROD_LOG_

            SLog::log("Error constructing RV Binary to State.");
            SLog::log("The word on line: " + std::to_string(line_count) + " is invalid.");

            #else

            std::cout << SColor::red << "Error constructing rv binary to state." << SColor::nc << std::endl;
            std::cout << SColor::red << "The word on line: " << line_count << " is invalid." << SColor::nc << std::endl;

            #endif


            return false;
        }

        initial_state.set_value_in_to_state(Cell{MEMORY, address, Word{word}});

        address += 4;

    }

    return true;

}
