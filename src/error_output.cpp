#include "error_output.hpp"

// Output error message
void Error_Out::out_error(int error_code_, int line_number_, std::string error_information_) {

    switch (error_code_) {
    case 1:
        std::cout << "Invalid rd on line " << line_number_ << "." << std::endl;
        break;
    case 2:
        std::cout << "Invalid rs1 on line " << line_number_ << "." << std::endl;
        break;
    case 3:
        std::cout << "Invalid rs2 on line " << line_number_ << "." << std::endl;
        break;
    case 4:
        std::cout << "Invalid immediate value on line " << line_number_ << "." << std::endl;
        break;
    case 5:
        std::cout << "Immediate value for branch or jump command on line " << line_number_ << " needs to be a multiple of two." << std::endl;
        break;
    case 6:
        std::cout << "Invalid pi on line " << line_number_ << "." << std::endl;
        break;
    case 7:
        std::cout << "Invalid po on line " << line_number_ << "." << std::endl;
        break;
    case 101:
        std::cout << "Instruction \"" << error_information_ << "\" not found on line " << line_number_ << "." << std::endl;
        break;
    case 102:
        std::cout << "Error in instruction formating on line " << line_number_ << ": " << error_information_ << std::endl;
        break;
    case 201:
        std::cout << "Duplicated definition for label: " << error_information_ << " on line " << line_number_ << "." << std::endl;
        break;
    case 202:
        std::cout << "Illegal label: " << error_information_ << " on line " << line_number_ << "." << std::endl;
        break;
    case 203:
        std::cout << "Label: " << error_information_ << " is used but never decleared on line " << line_number_ << "." << std::endl;
    
    default:
        break;
    }

}
