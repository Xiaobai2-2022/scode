#ifndef _MEMORY_CELL_HPP_
#define _MEMORY_CELL_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "word.hpp"

class Cell;

class Cell {

    private:
        bool is_reg;
        unsigned long id;
        Word value;

    public:
        Cell();                             // Default constructor
        Cell(bool, unsigned long);          // bool, unsigned long constructor, set the initial state for the cell
        Cell(bool, unsigned long, Word);    // bool, unsigned long, Word constructor, set the state for the cell

    public:
        bool cell_is_reg();
        unsigned long cell_id();
        Word read();
        Word write(Word);

    friend std::ostream &operator<<(std::ostream &, const Cell &);

};

#endif
