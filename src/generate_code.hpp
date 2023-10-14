#ifndef _GEN_CODE_HPP_
#define _GEN_CODE_HPP_

#include "word.hpp"

class Gen_Code {

    // R Type Instructions
    public:
        static Word add(unsigned int, unsigned int, unsigned int);

    // I Type Instructions
    public:
        static Word addi(unsigned int, unsigned int, unsigned int);

    // B Type Instructions
    public:
        static Word beq(unsigned int, unsigned int, unsigned int);

};

#endif
