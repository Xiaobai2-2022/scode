#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <iomanip>
#include <iostream>

#include "memory_cell.hpp"
#include "memory.hpp"
#include "port.hpp"
#include "reg.hpp"

class State;

class State {

    private:
        bool is_end;
        ulong PC;
        Reg registers;
        Memory memory;
        Port ports;
    
    public:
        State();                // Default constructor, set all value in register and ports to zero and initialize an empty memory

    public:
        void set_value_in_to_state(Cell);                                   // Force data into state
        void set_pc(ulong);                                                 // Force PC value
        void force_end();                                                   // Force state to end

    public:
        Word get_value_in_state(unsigned int, ulong);                       // Read data from state
        ulong get_pc();                                                     // Read PC value
        bool get_is_end();                                                  // Read if the state is ended

    public:
        State &operator++();                                                // Increment PC by 4
        void init();                                                        // Reset the state
        
    friend std::ostream &operator<<(std::ostream &, const State &);

};

#endif
