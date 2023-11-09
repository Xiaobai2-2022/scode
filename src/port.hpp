#ifndef _PORT_HPP_
#define _PORT_HPP_

#include <iostream>

#include "memory_cell.hpp"

class Port;

class Port {

    public:
        static const ulong NUM_CELL = 8;

    private:
        Cell port_cells[NUM_CELL];          // Default constructor, set all ports to zero

    public:
        Port();
    
    public:
        Word read_cell(ulong);
        Word write_cell(ulong, Word);
    
    friend std::ostream &operator<<(std::ostream &, const Port &);

};

#endif
