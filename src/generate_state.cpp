#include "generate_state.hpp"

// Interperate and update State
int Gen_State::update_state(State &state_) {

    // Read memory at PC
    ulong PC = state_.get_pc();
    Word mem_at_pc = state_.get_value_in_state(MEMORY, PC);

    // Increment PC by 4
    ++state_;

    // Grab the opcode from the memory
    Word opcode = mem_at_pc.limit(6);

    if(opcode == 0b0110011) {

        // Read the function7 and function 3 from the memory
        Word funct7 = mem_at_pc.limit(31, 25);
        Word funct3 = mem_at_pc.limit(14, 12);

        // Read the registers from the memory
        Word rd = mem_at_pc.limit(11, 7);
        Word rs1 = mem_at_pc.limit(19, 15);
        Word rs2 = mem_at_pc.limit(24, 20);

        if((funct7 == 0x00) && (funct3 == 0x0)) {
            return Gen_State::ADD(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
        }

    }

    return 0;

}

// R-type Instruction add: rd = rs1 + rs2
int Gen_State::ADD(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 + val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}
