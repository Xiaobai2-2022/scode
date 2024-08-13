#include "error_output.hpp"

// Output error message
void Error_Out::out_error(int error_code, int line_number, std::string error_information) {

    switch (error_code) {
    case 1:
        std::cout << SStyle::RED << "Invalid rd on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 2:
        std::cout << SStyle::RED << "Invalid rs1 on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 3:
        std::cout << SStyle::RED << "Invalid rs2 on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 4:
        std::cout << SStyle::RED << "Invalid immediate value on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 5:
        std::cout << SStyle::RED << "Immediate value for branch or jump command on line " << line_number << " needs to be a multiple of two." << SStyle::NC << std::endl;
        break;
    case 6:
        std::cout << SStyle::RED << "Invalid pi on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 7:
        std::cout << SStyle::RED << "Invalid po on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 101:
        std::cout << SStyle::RED << "Instruction \"" << error_information << "\" not found on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 102:
        std::cout << SStyle::RED << "Error in instruction formating on line " << line_number << ": " << error_information << SStyle::NC << std::endl;
        break;
    case 201:
        std::cout << SStyle::RED << "Duplicated definition for label: " << error_information << " on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 202:
        std::cout << SStyle::RED << "Illegal label: " << error_information << " on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    case 203:
        std::cout << SStyle::RED << "Label: " << error_information << " is used but never decleared on line " << line_number << "." << SStyle::NC << std::endl;
        break;
    
    default:
        break;
    }

}
