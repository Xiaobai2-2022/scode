#include "memory_cell.hpp"

// Default constructor, set the initial state for the cell
Cell::Cell() : type{0}, id{0}, value{Word{}} {};

// unsigned int, unsigned long constructor, set the initial state for the cell
Cell::Cell(unsigned int type_ , ulong id_) : type{type_}, id{id_}, value{Word{}} {};

// unsigned int, unsigned long, Word constructor, set the state for the cell
Cell::Cell(unsigned int type_, ulong id_, Word val_) : type{type_}, id{id_}, value{val_} {};

// Returns the id of the cell
ulong Cell::cell_id() { return this->id; };

// Return the value
Word Cell::read() { return this->value; }

// Set the value to new value, return the original value
Word Cell::write(Word val_) {
    Word temp = this->value;
    this->value = val_;
    return temp;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Cell &c) {

    if(c.type == 1) {
        os << "Reg(" << "0x" << std::setfill('0') << std::setw(2) << std::hex << c.id << "): ";
    } else if(c.type == 0) {
        os << "Mem(" << "0x" << std::setfill('0') << std::setw(8) << std::hex << c.id << "): ";
    } else {
        os << "Port(" << "0x" << std::setfill('0') << std::setw(1) << std::hex << c.id << "): ";
    }

    os << c.value << std::endl;

    return os;

}
