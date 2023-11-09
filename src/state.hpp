#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <iostream>

#include "memory_cell.hpp"
#include "memory.hpp"
#include "port.hpp"
#include "reg.hpp"

class State;

class State {

    private:
        ulong PC;
        Reg registers;
        Memory memory;
        Port ports;
    
    public:
        State();                // Default constructor, set all value in register and ports to zero and initialize an empty memory

    public:
        void force_value_in_to_state(Cell);                                     // For test purpose only, force data into state

    public:
        // State interperate_command();                                            // Interperate the current PC command, and call the correct function to generate new state
        
    friend std::ostream &operator<<(std::ostream &, const State &);

};

#endif
