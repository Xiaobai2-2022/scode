#ifndef _GEN_STATE_HPP_
#define _GEN_STATE_HPP_

#include "../senv/s_env_setting.hpp"

#include "../sdatas/memory_cell.hpp"
#include "../sdatas/state.hpp"
#include "../sdatas/word.hpp"

#include "../sutils/utility.hpp"

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

    // S Type Instructions
    public:
        static int SB(unsigned int, unsigned int, Word, State &);
        static int SH(unsigned int, unsigned int, Word, State &);
        static int SW(unsigned int, unsigned int, Word, State &);

    // B Type Instructions
    public:
        static int BEQ(unsigned int, unsigned int, Word, State &);
        static int BNE(unsigned int, unsigned int, Word, State &);
        static int BLT(unsigned int, unsigned int, Word, State &);
        static int BGE(unsigned int, unsigned int, Word, State &);
        static int BLTU(unsigned int, unsigned int, Word, State &);
        static int BGEU(unsigned int, unsigned int, Word, State &);

    // J Type Instructions
    public:
        static int JAL(unsigned int, Word, State &);

    // U Type Instructions
    public:
        static int LUI(unsigned int, Word, State &);
        static int AUIPC(unsigned int, Word, State &);

    // R (M) Type Instructions (RV32M Multiply Extension)
    public:
        static int MUL(unsigned int, unsigned int, unsigned int, State &);
        static int MULH(unsigned int, unsigned int, unsigned int, State &);
        static int MULSU(unsigned int, unsigned int, unsigned int, State &);
        static int MULU(unsigned int, unsigned int, unsigned int, State &);

    // SCode Instructions
    public:
        static int END(State &);
        static int NOP(State &);
        static int INPUT(unsigned int, unsigned int, State &);
        static int OUTPUT(unsigned int, unsigned int, State &);

};

#endif
