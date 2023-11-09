#include "reg.hpp"

// Default constructor, set all reg to zero
Reg::Reg() {

    // Set all cell to zero
    for(ulong i{0}; i < NUM_CELL; ++i) {
        reg_cells[i] = Cell{1, i};
    }

}

// Returns the value in the cell
Word Reg::read_cell(ulong index_) {
    return this->reg_cells[index_].read();
}

// Set the value of the cell to new value, return the original value of the cell
Word Reg::write_cell(Cell val_) {

    ulong index = val_.cell_id();

    if(index == 0) {
        return this->reg_cells[index].read();
    }
    Word temp = this->reg_cells[index].read();
    this->reg_cells[index] = val_;
    return temp;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Reg &r) {
    for(auto c : r.reg_cells) {
        os << c;
    }
    return os;
}
