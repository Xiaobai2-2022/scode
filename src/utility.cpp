#include "utility.hpp"

const std::unordered_map<std::string, int> Utility::inst = {

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

    {"lui", 35},
    {"auipc", 36},
    
    // {"ecall", 37},

    // {"ebreak", 38},

    // RV32M Multiply Extension
    {"mul", 50},
    {"mulh", 51},
    {"mulsu", 52},
    {"mulu", 53},
    {"div", 54},
    {"divu", 55},
    {"rem", 56},
    {"remu", 57},

    // SCode Extension
    {"end", 900},
    {"nop", 901},
    {"input", 902},
    {"output", 903},

    // Assembly Codes
    {"#", 1000},
    {"define", 1001}

};

// check if value is in between the lower and upper bound
bool Utility::is_in_range(unsigned int val, unsigned int lower, unsigned int upper) {

    if(val >= lower && val <= upper) {
        return true;
    }
    return false;

}

// Check if the string has the starting substring of the other string
bool Utility::is_start_with(std::string first, std::string second) {

    return first.find(second) == 0;

}

// Calculate the power of an integer value
int Utility::pow(int value, unsigned int power) {

    if(power == 0) return 1;

    int res{value};
    for(unsigned int i{1}; i < power; ++i) {
        res *= value;
    }
    return res;

}

// Convert the value into given length word
Word Utility::change_length(int value, unsigned int length) {

    if(value >= 0) {
        // Check if value is in range, if not, return the most significant value posible + 1
        if(value >= Utility::pow(2, length - 1)) {
            return Word{Utility::pow(2, length)};
        }
        return Word{value};
    }

    // Check if the negative value is in rangeu c
    if(abs(value) > Utility::pow(2, length - 1)) {
        return Word{Utility::pow(2, length)};
    }

    unsigned int u_value{static_cast<unsigned int>(value)};
    u_value = u_value << (32 - length);
    u_value = u_value >> (32 - length);

    return Word{u_value};

}

// Convert the value into given length word
Word Utility::change_length_unsigned(int value, unsigned int length) {

    if(value >= 0) {
        // Check if value is in range, if not, return the most significant value posible + 1
        if(value >= Utility::pow(2, length)) {
            return Word{Utility::pow(2, length)};
        }
        return Word{value};
    }

    return Word{Utility::pow(2, length)};

}
