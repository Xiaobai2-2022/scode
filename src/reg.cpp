#include "reg.hpp"

// Default constructor, set all reg to zero
Reg::Reg() {

    // Set all cell to zero
    for(ulong i{0}; i < NUM_CELL; ++i) {
        this->reg_cells[i] = Cell{1, i};
    }

    // Points to the top of the stack, which is 0x03fffffffc
    this->reg_cells[STACK_PTR].write(Word{0xffffffff});

}

// Returns the value in the cell
Word Reg::read_cell(ulong index) {
    return this->reg_cells[index].read();
}

// Set the value of the cell to new value, return the original value of the cell
Word Reg::write_cell(Cell val) {

    ulong index = val.cell_id();

    if(index == ZERO) {
        return this->reg_cells[index].read();
    }
    Word temp = this->reg_cells[index].read();
    this->reg_cells[index] = val;
    return temp;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Reg &r) {
    for(auto c : r.reg_cells) {
        os << c;
    }
    return os;
}
