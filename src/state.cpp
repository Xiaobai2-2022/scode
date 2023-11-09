#include "state.hpp"

// Default constructor, set all value in register and ports to zero and initialize an empty memory
State::State() : PC{}, registers{Reg{}}, memory{Memory{}}, ports{Port{}} {}

// For test purpose only, force data into state
void State::force_value_in_to_state(Cell val_) {

    if(val_.get_type() == 0) {
        this->memory.add_to_back(val_);
    } else if(val_.get_type() == 1) {
        this->registers.write_cell(val_);
    } else {
        this->ports.write_cell(val_);
    }

}

// Output operator
std::ostream &operator<<(std::ostream &os, const State &s) {

    os << "PC: " << s.PC << std::endl << std::endl;
    os << "Register: " << std::endl;
    os << s.registers << std::endl;
    os << "Port: " << std::endl;
    os << s.ports << std::endl;
    
    os << "Memory: " << std::endl;
    for(auto it{s.memory.cbegin()}; it != s.memory.cend(); ++it) {
        os << (*it);
    }
    os << std::endl;

    return os;

}
