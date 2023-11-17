#include "state.hpp"

// Default constructor, set all value in register and ports to zero and initialize an empty memory
State::State() : PC{}, registers{Reg{}}, memory{Memory{}}, ports{Port{}} {}

// Force data into state
void State::set_value_in_to_state(Cell val) {

    if(val.get_type() == MEMORY) {
        this->memory.add_to_back(val);
    } else if(val.get_type() == REGISTER) {
        this->registers.write_cell(val);
    } else {
        this->ports.write_cell(val);
    }

}

// Force PC value
void State::set_pc(ulong pc_) {
    this->PC = pc_;
}

// Read data from state
Word State::get_value_in_state(unsigned int type, ulong id) {

    if(type == MEMORY) {
        return this->memory.read(id).read();
    } else if(type == REGISTER) {
        return this->registers.read_cell(id);
    } else {
        return this->ports.read_cell(id);
    }

}

ulong State::get_pc() {
    return this->PC;
}

// Increment PC by 4
State &State::operator++() {
    this->PC += 4;
    return *this;
}

// Resets the state
void State::init() {

    this->PC = 0;
    this->memory.clear();
    this->registers = Reg{};
    this->ports = Port{};
    
}

// Output operator
std::ostream &operator<<(std::ostream &os, const State &s) {

    os << "PC: " << "0x" << std::setfill('0') << std::setw(9) << std::hex << s.PC << std::endl << std::endl;
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
