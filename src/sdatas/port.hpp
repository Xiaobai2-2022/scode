#ifndef _PORT_HPP_
#define _PORT_HPP_

#include "../senv/s_env_setting.hpp"

#include <iostream>

#include "memory_cell.hpp"

class Port;

class Port {

    public:
        static const ulong NUM_CELL = 8;

    private:
        Cell port_cells[NUM_CELL];

    public:
        Port();             // Default constructor, set all ports to zero
        Port(const Port &);       // Copy constructor, copy all ports

    public:
        Word read_cell(ulong);
        Word write_cell(Cell);
    
    friend std::ostream &operator<<(std::ostream &, const Port &);

};

#endif
