#ifndef _REG_HPP_
#define _REG_HPP_

#include <iostream>

#include "memory_cell.hpp"

class Reg;

class Reg {

    public:
        static const unsigned long NUM_CELL = 32;

    private:
        Cell reg_cells[32];

    public:
        Reg();          // Default constructor, set all reg to zero

    public:
        Word read_cell(unsigned long);
        Word write_cell(unsigned long, Word);

    friend std::ostream &operator<<(std::ostream &, const Reg &);

};

#endif
