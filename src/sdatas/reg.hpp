#ifndef _REG_HPP_
#define _REG_HPP_

#include "../senv/s_env_setting.hpp"

#include <iostream>

#include "memory_cell.hpp"

class Reg;

class Reg {

    public:
        static const ulong NUM_CELL = 32;

    public:
        static const ulong ZERO = 0;
        static const ulong RETURN_ADDR = 1;
        static const ulong STACK_PTR = 2;
        static const ulong GLOBAL_PTR = 3;
        static const ulong THREAD_PTR = 4;
        static const ulong TEMP_0 = 5;
        static const ulong ALT_LINK = 5;
        static const ulong TEMP_1 = 6;
        static const ulong TEMP_2 = 7;
        static const ulong SAVE_0 = 8;
        static const ulong FRAME_PTR = 8;
        static const ulong SAVE_1 = 9;
        static const ulong FUNC_ARGS_0 = 10;
        static const ulong FUNC_RETURN_0 = 10;
        static const ulong FUNC_ARGS_1 = 11;
        static const ulong FUNC_RETURN_1 = 11;
        static const ulong FUNC_ARGS_2 = 12;
        static const ulong FUNC_ARGS_3 = 13;
        static const ulong FUNC_ARGS_4 = 14;
        static const ulong FUNC_ARGS_5 = 15;
        static const ulong FUNC_ARGS_6 = 16;
        static const ulong FUNC_ARGS_7 = 17;
        static const ulong SAVE_2 = 18;
        static const ulong SAVE_3 = 19;
        static const ulong SAVE_4 = 20;
        static const ulong SAVE_5 = 21;
        static const ulong SAVE_6 = 22;
        static const ulong SAVE_7 = 23;
        static const ulong SAVE_8 = 24;
        static const ulong SAVE_9 = 25;
        static const ulong SAVE_10 = 26;
        static const ulong SAVE_11 = 27;
        static const ulong TEMP_3 = 28;
        static const ulong TEMP_4 = 29;
        static const ulong TEMP_5 = 30;
        static const ulong TEMP_6 = 31;

    private:
        Cell reg_cells[NUM_CELL];

    public:
        Reg();          // Default constructor, set all registers to zero
        Reg(const Reg &);     // Copy constructor, copy all registers

    public:
        Word read_cell(ulong);
        Word write_cell(Cell);

    friend std::ostream &operator<<(std::ostream &, const Reg &);

};

#endif
