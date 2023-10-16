#include "utility.hpp"

const std::map<std::string, int> Utility::rv_inst = {

    // RV32I Base Integer Instructions
    {"add", 0},
    {"sub", 1},
    {"xor", 2},
    {"or", 3},
    {"and", 4},
    {"sll", 5},
    {"srl", 6},
    {"sra", 7},
    {"slt", 8},
    {"sltu", 9},

    {"addi", 10},
    {"xori", 11},
    {"ori", 12},
    {"andi", 13},
    {"slli", 14},
    {"srli", 15},
    {"srai", 16},
    {"slti", 17},
    {"sltiu", 18},

    {"lb", 19},
    {"lh", 20},
    {"lw", 21},
    {"lbu", 22},
    {"lhu", 23},

    {"sb", 24},
    {"sh", 25},
    {"sw", 26},

    {"beq", 27},
    {"bne", 28},
    {"blt", 29},
    {"bge", 30},
    {"bltu", 31},
    {"bgeu", 32},
    
    {"jal", 33},
    {"jalr", 34},

    // RV32M Multiply Extension
    {"mul", 50},
    {"mulh", 51},
    {"mulsu", 52},
    {"mulu", 53},
    {"div", 54},
    {"divu", 55},
    {"rem", 56},
    {"remu", 57}

};

// check if value is in between the lower and upper bound
bool Utility::is_in_range(unsigned int val_, unsigned int lower_, unsigned int upper_) {

    if(val_ >= lower_ && val_ <= upper_) {
        return true;
    }
    return false;

}

// Check if the string has the starting substring of the other string
bool Utility::is_start_with(std::string first_, std::string second_) {

    return first_.find(second_) == 0;

}