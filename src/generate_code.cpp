#include "generate_code.hpp"

#include "utility.hpp"

// If there is an error, the command will return 0;

// R-type Instruction add: rd = rs1 + rs2
std::pair<Word, int> Gen_Code::add(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    unsigned int funct7 = 0x00;
    unsigned int funct3 = 0x0;
    unsigned int opcode = 0b0110011;

    // Calculate result
    unsigned int result = 
        funct7 * 0b10000000000000000000000000 +
        rs2_ * 0b100000000000000000000 +
        rs1_ * 0b1000000000000000 +
        funct3 * 0b1000000000000 +
        rd_ * 0b10000000 +
        opcode;

    return std::pair<Word, int>{Word{result}, 0};

}

// // B-type Instruction beq: if(rs1 == rs2) PC += imm
// std::pair<Word, int> Gen_Code::beq(unsigned int rs1_, unsigned int rs2_, Word imm) {

// }
