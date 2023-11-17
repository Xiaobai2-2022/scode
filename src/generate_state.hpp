#ifndef _GEN_STATE_HPP_
#define _GEN_STATE_HPP_

#include "memory_cell.hpp"
#include "state.hpp"
#include "word.hpp"
#include "utility.hpp"

class Gen_State;

class Gen_State {

    // Interperate and update State
    public:
        static int update_state(State &);

    // R Type Instructions
    private:
        static int ADD(unsigned int, unsigned int, unsigned int, State &);
        static int SUB(unsigned int, unsigned int, unsigned int, State &);
        static int XOR(unsigned int, unsigned int, unsigned int, State &);
        static int OR(unsigned int, unsigned int, unsigned int, State &);
        static int AND(unsigned int, unsigned int, unsigned int, State &);
        static int SLL(unsigned int, unsigned int, unsigned int, State &);
        static int SRL(unsigned int, unsigned int, unsigned int, State &);
        static int SRA(unsigned int, unsigned int, unsigned int, State &);
        static int SLT(unsigned int, unsigned int, unsigned int, State &);
        static int SLTU(unsigned int, unsigned int, unsigned int, State &);
    
    // I Type Instructions
    public:
        static int ADDI(unsigned int, unsigned int, Word, State &);
        static int XORI(unsigned int, unsigned int, Word, State &);
        static int ORI(unsigned int, unsigned int, Word, State &);
        static int ANDI(unsigned int, unsigned int, Word, State &);
        static int SLLI(unsigned int, unsigned int, Word, State &);
        static int SRLI(unsigned int, unsigned int, Word, State &);
        static int SRAI(unsigned int, unsigned int, Word, State &);
        static int SLTI(unsigned int, unsigned int, Word, State &);
        static int SLTIU(unsigned int, unsigned int, Word, State &);

        static int LB(unsigned int, unsigned int, Word, State &);
        static int LH(unsigned int, unsigned int, Word, State &);
        static int LW(unsigned int, unsigned int, Word, State &);
        static int LBU(unsigned int, unsigned int, Word, State &);
        static int LHU(unsigned int, unsigned int, Word, State &);

        static int JALR(unsigned int, unsigned int, Word, State &);

};

#endif
