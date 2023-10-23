#ifndef _GEN_CODE_HPP_
#define _GEN_CODE_HPP_

#include "word.hpp"
#include "utility.hpp"

class Gen_Code {

    // R Type Instructions
    public:
        static std::pair<Word, int> ADD(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SUB(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> XOR(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> OR(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> AND(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SLL(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SRL(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SRA(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SLT(unsigned int, unsigned int, unsigned int);
        static std::pair<Word, int> SLTU(unsigned int, unsigned int, unsigned int);

    // I Type Instructions
    public:
        static std::pair<Word, int> ADDI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> XORI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> ORI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> ANDI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SLLI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SRLI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SRAI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SLTI(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SLTIU(unsigned int, unsigned int, Word);

        static std::pair<Word, int> LB(unsigned int, unsigned int, Word);
        static std::pair<Word, int> LH(unsigned int, unsigned int, Word);
        static std::pair<Word, int> LW(unsigned int, unsigned int, Word);
        static std::pair<Word, int> LBU(unsigned int, unsigned int, Word);
        static std::pair<Word, int> LHU(unsigned int, unsigned int, Word);

        static std::pair<Word, int> JALR(unsigned int, unsigned int, Word);

    // S Type Instructions
    public:
        static std::pair<Word, int> SB(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SH(unsigned int, unsigned int, Word);
        static std::pair<Word, int> SW(unsigned int, unsigned int, Word);

    // B Type Instructions
    public:
        static std::pair<Word, int> BEQ(unsigned int, unsigned int, Word);
        static std::pair<Word, int> BNE(unsigned int, unsigned int, Word);
        static std::pair<Word, int> BLT(unsigned int, unsigned int, Word);
        static std::pair<Word, int> BGE(unsigned int, unsigned int, Word);
        static std::pair<Word, int> BLTU(unsigned int, unsigned int, Word);
        static std::pair<Word, int> BGEU(unsigned int, unsigned int, Word);

    // J Type Instructions
    public:
        static std::pair<Word, int> JAL(unsigned int, Word);

    // U Type Instructions
    public:
        static std::pair<Word, int> LUI(unsigned int, Word);
        static std::pair<Word, int> AUIPC(unsigned int, Word);

};

#endif
