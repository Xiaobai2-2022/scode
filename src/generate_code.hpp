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

    // B Type Instructions
    public:
        static std::pair<Word, int> BEQ(unsigned int, unsigned int, Word);

};

#endif
