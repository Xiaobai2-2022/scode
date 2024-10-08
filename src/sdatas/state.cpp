#include "state.hpp"

// Default constructor, set all value in register and ports to zero and initialize an empty memory
State::State() : is_end{false}, PC{}, registers{Reg{}}, memory{Memory{}}, ports{Port{}} {}

// Copy constructor, used to copy all elements in the state other
State::State(const State &other) : is_end{other.is_end}, PC{other.PC} {

    this->registers = other.registers;
    this->memory = other.memory;
    this->ports = other.ports;

}

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

// Force state to end
void State::force_end() {
    this->is_end = true;
}

// Read data from state
Word State::get_value_in_state(unsigned int type, ulong id) const {

    if(type == MEMORY) {
        return this->memory.read(id).read();
    } else if(type == REGISTER) {
        return this->registers.read_cell(id);
    } else {
        return this->ports.read_cell(id);
    }

}

ulong State::get_pc() const {
    return this->PC;
}

bool State::get_is_end() const {
    return this->is_end;
}

Memory State::get_mem() const {
    return this->memory;
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
        os << (*it) << std::endl;
    }
    os << std::endl;

    if(s.is_end) {
        os << std::endl;
        os << "======= End of State =======" << std::endl;
    }

    return os;

}
