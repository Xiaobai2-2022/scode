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
    case 101:
        std::cout << "Instruction \"" << error_information_ << "\" not found on line " << line_number_ << "." << std::endl;
    
    default:
        break;
    }

}
