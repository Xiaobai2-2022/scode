#include "construct_risc_v.hpp"

// Constructs Risc-V assembly command to binary code by reading file and output
//     if_name_ is the input file name
//     of_name_ is the output file name
bool Ctor_RV::rv_assembly0_to_bin(std::string if_name_, std::string of_name_) {

    bool no_error{true};

    // For error checking usage
    unsigned long count{1};

    // Attempt to open input and output file
    std::ifstream fin(if_name_);
    std::ofstream fout(of_name_);
    
    // Check if the input file failed to open
    if(!fin.is_open()) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Error opening the input file: " << if_name_ << "." << std::endl;
        return false;
    }
    // Check if the output file failed to open
    if(!fout.is_open()) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Error opening the output file: " << of_name_ << "." << std::endl;
        return false;
    }

    std::string cur_line;
    std::getline(fin, cur_line);

    // Check if the risc-v assembly file is of the correct type
    if(!Utility::is_start_with(cur_line, "Scode Assembly 0")) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Input file has the wrong type: " << if_name_ << "." << std::endl;
        return false;
    }

    // Output the scode header
    fout << "Scode Binary, Generated By Ctor_RV." << std::endl;

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        count++;

        std::string inst;

        int rd, rs1, rs2;       // reg inputs
        int imm;                // immediate


        std::pair<Word, int> generate_output;

        // Construct the string stream to access all elements on the line
        std::stringstream ss_line(cur_line);
        
        // Read the instruction
        ss_line >> inst;

        // Attempt to find the instruction in map
        auto it = Utility::rv_inst.find(inst);

        if(it != Utility::rv_inst.end()) {
            int inst_code = it->second;

            switch (inst_code) {
            case 0: // case add
                // Input rd, rs1, rs2 and generate code
                if(ss_line >> rd >> rs1 >> rs2) {
                    generate_output = Gen_Code::add(rd, rs1, rs2);
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "Command \"add\" should have format: \"add rd rs1 rs2\".");
                    no_error = false;
                }
                break;

            case 10: // case addi
                // Input rd, rs1, imm and generate code
                if(ss_line >> rd >> rs1 >> imm) {
                    generate_output = Gen_Code::addi(rd, rs1, Utility::change_length(imm, 12));
                    if(generate_output.second == 0) {
                    fout << generate_output.first << std::endl;
                    } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(generate_output.second, count, "");
                    no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "Command \"addi\" should have format: \"addi rd rs1 imm\".");
                    no_error = false;
                }
                break;
                
            default:
                break;
            }

        } else {
            fout << "!!! Error line !!!" << std::endl;
            std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
            Error_Out::out_error(101, count, inst);
            no_error = false;
        }

    }

    return no_error;

}
