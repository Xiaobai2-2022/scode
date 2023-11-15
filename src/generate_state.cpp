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

    // The function3 and function 7
    Word funct3, funct7;

    // The rd, rs1, rs2
    Word rd, rs1, rs2;
        

    switch (opcode.get_value()) {
    case 0b0110011: // Case S-type instruction with opcode 0110011
    
        // Read the function3 and function 7 from the memory
        funct3 = mem_at_pc.limit(14, 12);
        funct7 = mem_at_pc.limit(31, 25);

        // Read the registers from the memory
        rd = mem_at_pc.limit(11, 7);
        rs1 = mem_at_pc.limit(19, 15);
        rs2 = mem_at_pc.limit(24, 20);

        switch (funct3.get_value()) {
        case 0x0:
            switch (funct7.get_value()) {
            case 0x00: // add command
                return Gen_State::ADD(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            case 0x20: // sub command
                return Gen_State::SUB(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x4:
            switch (funct7.get_value()) {
            case 0x00: // xor command
                return Gen_State::XOR(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x6:
            switch (funct7.get_value()) {
            case 0x00: // or command
                return Gen_State::OR(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x7:
            switch (funct7.get_value()) {
            case 0x00: // xor command
                return Gen_State::AND(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x1:
            switch (funct7.get_value()) {
            case 0x00: // sll command
                return Gen_State::SLL(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x5:
            switch (funct7.get_value()) {
            case 0x00: // srl command
                return Gen_State::SRL(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            case 0x20: // sra command
                return Gen_State::SRA(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x2:
            switch (funct7.get_value()) {
            case 0x00: // slt command
                return Gen_State::SLT(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        case 0x3:
            switch (funct7.get_value()) {
            case 0x00: // sltu command
                return Gen_State::SLTU(rd.get_value(), rs1.get_value(), rs2.get_value(), state_);
                break;
            default:
                return -1;
            }
            break;
        
        default:
            return -1;
        }
        break;
    
    default:
        return -1;
    }

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
