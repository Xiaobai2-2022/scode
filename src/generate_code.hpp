#ifndef _GEN_CODE_HPP_
#define _GEN_CODE_HPP_

#include "word.hpp"

class Gen_Code {

    // R Type Instructions
    public:
        static Word add(int, int, int);

    // I Type Instructions
    public:
        static Word addi(int, int, int);

    // B Type Instructions
    public:
        static Word beq(int, int, int);

};

#endif
