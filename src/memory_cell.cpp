#include "memory_cell.hpp"

// Default constructor, set the initial state for the cell
Cell::Cell() : is_reg{false}, id{0}, value{Word{}} {};

// bool, unsigned long constructor, set the initial state for the cell
Cell::Cell(bool is_reg_, unsigned long id_) : is_reg{is_reg_}, id{id_}, value{Word{}} {};

// bool, unsigned long, Word constructor, set the state for the cell
Cell::Cell(bool is_reg_, unsigned long id_, Word val_) : is_reg{is_reg_}, id{id_}, value{val_} {};

// Returns if the cell is a register
bool Cell::cell_is_reg() { return this->is_reg; };

// Returns the id of the cell
unsigned long Cell::cell_id() { return this->id; };

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

    if(c.is_reg) {
        os << "Reg(" << "0x" << std::setfill('0') << std::setw(2) << std::hex << c.id << "): ";
    } else {
        os << "Mem(" << "0x" << std::setfill('0') << std::setw(8) << std::hex << c.id << "): ";
    }

    os << c.value << std::endl;

    return os;

}
