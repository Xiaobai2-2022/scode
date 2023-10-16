#ifndef _GEN_CODE_HPP_
#define _GEN_CODE_HPP_

#include "word.hpp"
#include "utility.hpp"

class Gen_Code {

    // R Type Instructions
    public:
        static std::pair<Word, int> add(unsigned int, unsigned int, unsigned int);

    // I Type Instructions
    public:
        static std::pair<Word, int> addi(unsigned int, unsigned int, unsigned int);

    // B Type Instructions
    public:
        static std::pair<Word, int> beq(unsigned int, unsigned int, Word);

};

#endif
