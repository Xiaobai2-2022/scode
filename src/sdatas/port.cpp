#include "port.hpp"

// Default constructor, set all reg to zero
Port::Port() {

    // Set all ports to zero
    for(ulong i{0}; i < NUM_CELL; ++i) {
        port_cells[i] = Cell{2, i};
    }

}

Port::Port(const Port &other) {

    for(ulong i{0}; i < NUM_CELL; ++i) {
        port_cells[i] = other.port_cells[i];
    }

}

// Returns the value in the cell
Word Port::read_cell(ulong index) const {
    return this->port_cells[index].read();
}

// Set the value of the cell to new value, return the original value of the cell
Word Port::write_cell(Cell val) {

    ulong index = val.cell_id();

    Word temp = this->port_cells[index].read();
    this->port_cells[index] = val;
    return temp;

}

// Output operator
std::ostream &operator<<(std::ostream &os, const Port &p) {
    for(auto c : p.port_cells) {
        os << c << std::endl;
    }
    return os;
}
