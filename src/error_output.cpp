#include "error_output.hpp"

// Output error message
void Error_Out::out_error(int error_code, int line_number, std::string error_information) {

    switch (error_code) {
    case 1:
        std::cout << SColor::red << "Invalid rd on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 2:
        std::cout << SColor::red << "Invalid rs1 on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 3:
        std::cout << SColor::red << "Invalid rs2 on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 4:
        std::cout << SColor::red << "Invalid immediate value on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 5:
        std::cout << SColor::red << "Immediate value for branch or jump command on line " << line_number << " needs to be a multiple of two." << SColor::nc << std::endl;
        break;
    case 6:
        std::cout << SColor::red << "Invalid pi on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 7:
        std::cout << SColor::red << "Invalid po on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 101:
        std::cout << SColor::red << "Instruction \"" << error_information << "\" not found on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 102:
        std::cout << SColor::red << "Error in instruction formating on line " << line_number << ": " << error_information << SColor::nc << std::endl;
        break;
    case 201:
        std::cout << SColor::red << "Duplicated definition for label: " << error_information << " on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 202:
        std::cout << SColor::red << "Illegal label: " << error_information << " on line " << line_number << "." << SColor::nc << std::endl;
        break;
    case 203:
        std::cout << SColor::red << "Label: " << error_information << " is used but never decleared on line " << line_number << "." << SColor::nc << std::endl;
        break;
    
    default:
        break;
    }

}
