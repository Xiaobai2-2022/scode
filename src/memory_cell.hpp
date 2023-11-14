#ifndef _MEMORY_CELL_HPP_
#define _MEMORY_CELL_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "word.hpp"

#define MEMORY 0
#define REGISTER 1
#define PORT 2

class Cell;

class Cell {

    private:
        unsigned int type;
        ulong id;
        Word value;

    public:
        Cell();                             // Default constructor
        Cell(unsigned int, ulong);          // bool, unsigned long constructor, set the initial state for the cell
        Cell(unsigned int, ulong, Word);    // bool, unsigned long, Word constructor, set the state for the cell

    public:
        unsigned int get_type();
        ulong cell_id();
        Word read();
        Word write(Word);

    friend std::ostream &operator<<(std::ostream &, const Cell &);

};

#endif
