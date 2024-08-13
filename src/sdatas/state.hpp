#ifndef _STATE_HPP_
#define _STATE_HPP_

#include "../senv/s_env_setting.hpp"

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
        State(const State &);   // Copy constructor, used to copy all elements in the state other

    public:
        void set_value_in_to_state(Cell);                                   // Force data into state
        void set_pc(ulong);                                                 // Force PC value
        void force_end();                                                   // Force state to end

    public:
        Word get_value_in_state(unsigned int, ulong) const;                 // Read data from state
        ulong get_pc() const;                                               // Read PC value
        bool get_is_end() const;                                            // Read if the state is ended
        Memory get_mem() const;                                             // Read the memory 

    public:
        State &operator++();                                                // Increment PC by 4
        void init();                                                        // Reset the state
        
    friend std::ostream &operator<<(std::ostream &, const State &);

};

#endif
