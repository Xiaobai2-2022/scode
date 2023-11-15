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

        // Interperate command
        if(funct3 == 0x0) {
            if(funct7 == 0x00) {
                return Gen_State::ADD(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else if(funct7 == 0x20) {
                return Gen_State::SUB(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x4) {
            if(funct7 == 0x00) {
                return Gen_State::XOR(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x6) {
            if(funct7 == 0x00) {
                return Gen_State::OR(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x7) {
            if(funct7 == 0x00) {
                return Gen_State::AND(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x1) {
            if(funct7 == 0x00) {
                return Gen_State::SLL(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x5) {
            if(funct7 == 0x00) {
                return Gen_State::SRL(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else if(funct7 == 0x20) {
                return Gen_State::SRA(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else if(funct3 == 0x2) {
            if(funct7 == 0x00) {
                return Gen_State::SLT(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }

        } else if(funct3 == 0x3) {
            if(funct7 == 0x00) {
                return Gen_State::SLTU(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
            } else {
                return -1;
            }
        } else {
            return -1;
        }

    }

    return 0;

}

// R-type Instruction add: rd = rs1 + rs2
int Gen_State::ADD(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 + val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction sub: rd = rs1 - rs2
int Gen_State::SUB(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 - val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction xor: rd = rs1 ^ rs2
int Gen_State::XOR(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 ^ val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction or: rd = rs1 | rs2
int Gen_State::OR(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 | val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction or: rd = rs1 & rs2
int Gen_State::AND(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 & val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction sll: rd = rs1 << rs2
int Gen_State::SLL(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 << val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction srl: rd = rs1 >> rs2
int Gen_State::SRL(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1 >> val_rs2;

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction sra: rd = rs1 >> rs2
int Gen_State::SRA(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = val_rs1.SRA(val_rs2);

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction slt: rd = (rs1 < rs2) ? 1 : 0
int Gen_State::SLT(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = (static_cast<int>(val_rs1.get_value()) < static_cast<int>(val_rs2.get_value())) ? Word{1} : Word{0};

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}

// R-type Instruction sltu: rd = (rs1 < rs2) ? 1 : 0
int Gen_State::SLTU(unsigned int rd_, unsigned int rs1_, unsigned int rs2_, State &state_) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd_, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1_, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2_, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state_.get_value_in_state(REGISTER, rs1_);
    Word val_rs2 = state_.get_value_in_state(REGISTER, rs2_);
    Word val_rd = (val_rs1 < (val_rs2)) ? Word{1} : Word{0};

    state_.set_value_in_to_state(Cell{REGISTER, rd_, val_rd});

    return 0;

}
