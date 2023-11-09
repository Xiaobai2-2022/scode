#ifndef _REG_HPP_
#define _REG_HPP_

#include <iostream>

#include "memory_cell.hpp"

class Reg;

class Reg {

    public:
        static const ulong NUM_CELL = 32;

    private:
        Cell reg_cells[NUM_CELL];

    public:
        Reg();          // Default constructor, set all registers to zero

    public:
        Word read_cell(ulong);
        Word write_cell(Cell);

    friend std::ostream &operator<<(std::ostream &, const Reg &);

};

#endif
