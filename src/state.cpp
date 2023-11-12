#include "state.hpp"

// Default constructor, set all value in register and ports to zero and initialize an empty memory
State::State() : PC{}, registers{Reg{}}, memory{Memory{}}, ports{Port{}} {}

// Force data into state
void State::set_value_in_to_state(Cell val_) {

    if(val_.get_type() == MEMORY) {
        this->memory.add_to_back(val_);
    } else if(val_.get_type() == REGISTER) {
        this->registers.write_cell(val_);
    } else {
        this->ports.write_cell(val_);
    }

}

// Force PC value
void State::set_pc(ulong pc_) {
    this->PC = pc_;
}

// Read data from state
Word State::get_value_in_state(unsigned int type_, ulong id_) {

    if(type_ == MEMORY) {
        return this->memory.read(id_).read();
    } else if(type_ == REGISTER) {
        return this->registers.read_cell(id_);
    } else {
        return this->ports.read_cell(id_);
    }

}

ulong State::get_pc() {
    return this->PC;
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
