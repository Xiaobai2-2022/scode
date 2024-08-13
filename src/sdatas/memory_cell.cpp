#include "memory_cell.hpp"

// Default constructor, set the initial state for the cell
Cell::Cell() : type{0}, id{0}, value{Word{}} {};

// unsigned int, unsigned long constructor, set the initial state for the cell
Cell::Cell(unsigned int type , ulong id) : type{type}, id{id}, value{Word{}} {};

// unsigned int, unsigned long, Word constructor, set the state for the cell
Cell::Cell(unsigned int type, ulong id, Word val) : type{type}, id{id}, value{val} {};

// Copy constructor, copies the other cell's state
Cell::Cell(const Cell &other) : type{other.type}, id{other.id}, value{other.value} {}

// Returns the type of the cell
unsigned int Cell::get_type() { return this->type; }

// Returns the id of the cell
ulong Cell::cell_id() { return this->id; };

// Return the value
Word Cell::read() { return this->value; }

// Set the value to new value, return the original value
Word Cell::write(Word val) {
    Word temp = this->value;
    this->value = val;
    return temp;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Cell &c) {

    #ifdef _SVM_PROD_DISP_

    if((c.type != MEMORY && c.id % 2 == 0) || (c.type == MEMORY && c.id % 8 == 0)) {
        os << SColor::blue;
    } else {
        os << SColor::cyan;
    }


    #endif

    if(c.type == REGISTER) {
        os << "Reg(" << "0x" << std::setfill('0') << std::setw(2) << std::hex << c.id << "): ";
    } else if(c.type == MEMORY) {
        os << "Mem(" << "0x" << std::setfill('0') << std::setw(9) << std::hex << c.id << "): ";
    } else {
        os << "Port(" << "0x" << std::setfill('0') << std::setw(1) << std::hex << c.id << "): ";
    }

    #ifdef _SVM_PROD_DISP_

    os << c.value << " <- 0x" << std::setw(8) << std::hex << c.value.get_value() << SColor::nc << std::endl;

    #endif

    return os;

}
