#include "generate_code.hpp"

#include "utility.hpp"

// R-type Instruction add: rd = rs1 + rs2
std::pair<Word, int> Gen_Code::ADD(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction sub: rd = rs1 - rs2
std::pair<Word, int> Gen_Code::SUB(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x20;
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction xor: rd = rs1 ^ rs2
std::pair<Word, int> Gen_Code::XOR(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x4;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction or: rd = rs1 | rs2
std::pair<Word, int> Gen_Code::OR(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x6;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction and: rd = rs1 & rs2
std::pair<Word, int> Gen_Code::AND(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x7;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction sll: rd = rs1 << rs2
std::pair<Word, int> Gen_Code::SLL(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction srl: rd = rs1 >> rs2
std::pair<Word, int> Gen_Code::SRL(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction sra: rd = rs1 >> rs2
std::pair<Word, int> Gen_Code::SRA(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x20;
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction slt: rd = (rs1 < rs2) ? 1 : 0
std::pair<Word, int> Gen_Code::SLT(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x2;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R-type Instruction sltu: rd = (rs1 < rs2) ? 1 : 0
std::pair<Word, int> Gen_Code::SLTU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x3;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// I-type Instruction addi: rd = rs1 + imm
std::pair<Word, int> Gen_Code::ADDI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction xori: rd = rs1 ^ imm
std::pair<Word, int> Gen_Code::XORI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x4;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction ori: rd = rs1 | imm
std::pair<Word, int> Gen_Code::ORI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x6;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction andi: rd = rs1 & imm
std::pair<Word, int> Gen_Code::ANDI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x7;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction slli: rd = rs1 << imm [0 : 4]
std::pair<Word, int> Gen_Code::SLLI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 5) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b0010011;
    const unsigned int imm5to11 = 0x00;

    Word result{};
    result +=
        (imm_ << 27) +
        (imm5to11 << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction srli: rd = rs1 >> imm [0 : 4]
std::pair<Word, int> Gen_Code::SRLI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 5) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0010011;
    const unsigned int imm5to11 = 0x00;

    Word result{};
    result +=
        (imm_ << 27) +
        (imm5to11 << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction SRAI: rd = rs1 >> imm [0 : 4]
std::pair<Word, int> Gen_Code::SRAI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 5) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0010011;
    const unsigned int imm5to11 = 0x20;

    Word result{};
    result +=
        (imm_ << 27) +
        (imm5to11 << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction slti: rd = (rs1 < imm) ? 1 : 0
std::pair<Word, int> Gen_Code::SLTI(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x2;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction sltiu: rd = (rs1 < imm) ? 1 : 0
std::pair<Word, int> Gen_Code::SLTIU(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x3;
    const unsigned int opcode = 0b0010011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction lb: rd = M[rs + imm][0 : 7]
std::pair<Word, int> Gen_Code::LB(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0000011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction lh: rd = M[rs + imm][0 : 15]
std::pair<Word, int> Gen_Code::LH(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b0000011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction lw: rd = M[rs + imm][0 : 31]
std::pair<Word, int> Gen_Code::LW(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x2;
    const unsigned int opcode = 0b0000011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction lbu: rd = M[rs + imm][0 : 7]
std::pair<Word, int> Gen_Code::LBU(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x4;
    const unsigned int opcode = 0b0000011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// I-type Instruction lhu: rhu = M[rs + imm][0 : 15]
std::pair<Word, int> Gen_Code::LHU(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0000011;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// S-type Instruction sb: M[rs + imm][0 : 7] = rs2[0 : 7]
std::pair<Word, int> Gen_Code::SB(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0100011;

    Word result{};
    result +=
        (imm_.limit(11, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 0) << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// S-type Instruction sh: M[rs + imm][0 : 15] = rs2[0 : 15]
std::pair<Word, int> Gen_Code::SH(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b0100011;

    Word result{};
    result +=
        (imm_.limit(11, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 0) << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// S-type Instruction sw: M[rs + imm][0 : 31] = rs2[0 : 31]
std::pair<Word, int> Gen_Code::SW(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x2;
    const unsigned int opcode = 0b0100011;

    Word result{};
    result +=
        (imm_.limit(11, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 0) << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// B-type Instruction beq: if(rs1 == rs2) PC += imm
std::pair<Word, int> Gen_Code::BEQ(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// B-type Instruction bne: if(rs1 != rs2) PC += imm
std::pair<Word, int> Gen_Code::BNE(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// B-type Instruction blt: if(rs1 < rs2) PC += imm
std::pair<Word, int> Gen_Code::BLT(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x4;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// B-type Instruction bge: if(rs1 >= rs2) PC += imm
std::pair<Word, int> Gen_Code::BGE(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// B-type Instruction beq: if(rs1 < rs2) PC += imm
std::pair<Word, int> Gen_Code::BLTU(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x6;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// B-type Instruction beq: if(rs1 >= rs2) PC += imm
std::pair<Word, int> Gen_Code::BGEU(unsigned int rs1_, unsigned int rs2_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int funct3 = 0x7;
    const unsigned int opcode = 0b1100011;
    
    Word result{};
    result +=
        (imm_.limit(12, 12) << 31) +
        (imm_.limit(10, 5) << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (imm_.limit(4, 1) << 8) +
        (imm_.limit(11, 11) << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// J-type Instruction jal: rd = PC + 4; PC += imm
std::pair<Word, int> Gen_Code::JAL(unsigned int rd_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    // Check if the immediate value is in range
    if((imm_ >> 20) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Shift immediate value by 1 bit
    imm_ <<= 1;

    // Check if the immediate value a multiply of 4, since the jump should be a multiply of 4
    if((imm_ % 4) != Word{0}) return std::pair<Word, int>{Word{}, 5};

    // Define constant values
    const unsigned int opcode = 0b1101111;
    
    Word result{};
    result +=
        (imm_.limit(20, 20) << 31) +
        (imm_.limit(10, 1) << 21) +
        (imm_.limit(11, 11) << 20) +
        (imm_.limit(19, 12) << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// I-type Instruction jalr: rd = PC + 4; PC = rs1 + imm
std::pair<Word, int> Gen_Code::JALR(unsigned int rd_, unsigned int rs1_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if the immediate value is in range
    if((imm_ >> 12) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b1100111;

    Word result{};
    result +=
        (imm_ << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// U-type Instruction lui: rd = imm << 12
std::pair<Word, int> Gen_Code::LUI(unsigned int rd_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    // Check if the immediate value is in range
    if((imm_ >> 20) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int opcode = 0b0110111;

    Word result{};
    result +=
        (imm_ << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// U-type Instruction auipc: rd = imm << 12
std::pair<Word, int> Gen_Code::AUIPC(unsigned int rd_, Word imm_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    // Check if the immediate value is in range
    if((imm_ >> 20) == Word{1}) return std::pair<Word, int>{Word{}, 4};

    // Define constant values
    const unsigned int opcode = 0b0010111;

    Word result{};
    result +=
        (imm_ << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});
    
    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction mul rd = (rs1 * rs2)[31 : 0]
std::pair<Word, int> Gen_Code::MUL(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction mulh rd = (rs1 * rs2)[63 : 32]
std::pair<Word, int> Gen_Code::MULH(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x1;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction mulsu rd = (rs1 * rs2)[63 : 32]
std::pair<Word, int> Gen_Code::MULSU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x2;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction mulu rd = (rs1 * rs2)[63 : 32]
std::pair<Word, int> Gen_Code::MULU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x3;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction div rd = rs1 / rs2
std::pair<Word, int> Gen_Code::DIV(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x4;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction divu rd = rs1 / rs2
std::pair<Word, int> Gen_Code::DIVU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x5;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction rem rd = rs1 % rs2
std::pair<Word, int> Gen_Code::REM(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x6;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// R(M)-type Instruction remu rd = rs1 % rs2
std::pair<Word, int> Gen_Code::REMU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    if(!Utility::is_in_range(rs2_, 0, 31)) return std::pair<Word, int>{Word{}, 3};

    // Define constant values
    const unsigned int funct7 = 0x01;
    const unsigned int funct3 = 0x7;
    const unsigned int opcode = 0b0110011;

    // Calculate result
    Word result{};
    result += 
        (Word{funct7} << 25) +
        (Word{rs2_} << 20) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// SCode Instruction end ends the program
std::pair<Word, int> Gen_Code::END() {

    // Define constant values
    const unsigned int opcode = 0b1111111;

    Word result{};
    result +=
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// Scode Instruction input rd = pi
std::pair<Word, int> Gen_Code::INPUT(unsigned int pi_, unsigned int rd_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return std::pair<Word, int>{Word{}, 1};
    // Check if all ports are in range
    if(!Utility::is_in_range(pi_, 0, 7)) return std::pair<Word, int>{Word{}, 6};

    // Define constant values
    const unsigned int funct7 = 0x00;
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b1111110;

    Word result{};
    result +=
        (Word{funct7} << 25) +
        (Word{pi_} << 15) +
        (Word{funct3} << 12) +
        (Word{rd_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}

// Scode Instruction output po = rs1
std::pair<Word, int> Gen_Code::OUTPUT(unsigned int po_, unsigned int rs1_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1_, 0, 31)) return std::pair<Word, int>{Word{}, 2};
    // Check if all ports are in range
    if(!Utility::is_in_range(po_, 0, 7)) return std::pair<Word, int>{Word{}, 7};

    // Define constant values
    const unsigned int funct7 = 0x20;
    const unsigned int funct3 = 0x0;
    const unsigned int opcode = 0b1111110;

    Word result{};
    result +=
        (Word{funct7} << 25) +
        (Word{rs1_} << 15) +
        (Word{funct3} << 12) +
        (Word{po_} << 7) +
        (Word{opcode});

    return std::pair<Word, int>{result, 0};

}
