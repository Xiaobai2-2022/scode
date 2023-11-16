#include "generate_state.hpp"

// Interperate and update State
int Gen_State::update_state(State &state) {

    // Read memory at PC
    ulong PC = state.get_pc();
    Word mem_at_pc = state.get_value_in_state(MEMORY, PC);

    // Increment PC by 4
    ++state;

    // Grab the opcode from the memory
    Word opcode = mem_at_pc.limit(6);

    // function3 and function 7
    Word funct3, funct7;

    // rd, rs1, rs2, imm
    Word rd, rs1, rs2, imm;
        

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
            case 0x00: // add instruction
                return Gen_State::ADD(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            case 0x20: // sub instruction
                return Gen_State::SUB(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x4:
            switch (funct7.get_value()) {
            case 0x00: // xor instruction
                return Gen_State::XOR(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x6:
            switch (funct7.get_value()) {
            case 0x00: // or instruction
                return Gen_State::OR(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x7:
            switch (funct7.get_value()) {
            case 0x00: // xor instruction
                return Gen_State::AND(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x1:
            switch (funct7.get_value()) {
            case 0x00: // sll instruction
                return Gen_State::SLL(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x5:
            switch (funct7.get_value()) {
            case 0x00: // srl instruction
                return Gen_State::SRL(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            case 0x20: // sra instruction
                return Gen_State::SRA(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x2:
            switch (funct7.get_value()) {
            case 0x00: // slt instruction
                return Gen_State::SLT(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        case 0x3:
            switch (funct7.get_value()) {
            case 0x00: // sltu instruction
                return Gen_State::SLTU(rd.get_value(), rs1.get_value(), rs2.get_value(), state);
                break;
            default:
                return -1;
            }
            break;
        
        default:
            return -1;
        }
        break;



    case 0b0010011: // Case I-type instruction with opcode 0010011
    
        // Read the function3 from the memory
        funct3 = mem_at_pc.limit(14, 12);

        // Read the registers from the memory
        rd = mem_at_pc.limit(11, 7);
        rs1 = mem_at_pc.limit(19, 15);

        switch (funct3.get_value()) {
        case 0x0: // addi instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::ADDI(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x4: // xori instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::XORI(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x6: // ori instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::ORI(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x7: // andi instrcution
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::ANDI(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x1:
            // Read the imm[5:11] from the memory
            imm = mem_at_pc.limit(26, 20);
            switch (imm.get_value()) {
            case 0x00: // slli instrcution
                // Read the imm[0:4] from the memory
                imm = mem_at_pc.limit(31, 27);
                return Gen_State::SLLI(rd.get_value(), rs1.get_value(), imm, state);
                break;
            default:
                return -1;
                break;
            }
            break;
        case 0x5:
            // Read the imm[5:11] from the memory
            imm = mem_at_pc.limit(26, 20);
            switch (imm.get_value()) {
            case 0x00: // srli instrcution
                // Read the imm[0:4] from the memory
                imm = mem_at_pc.limit(31, 27);
                return Gen_State::SRLI(rd.get_value(), rs1.get_value(), imm, state);
                break;
            case 0x20: // srai instrcution
                // Read the imm[0:4] from the memory
                imm = mem_at_pc.limit(31, 27);
                return Gen_State::SRAI(rd.get_value(), rs1.get_value(), imm, state);
                break;
            default:
                return -1;
                break;
            }
            break;
        case 0x2: // slti instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::SLTI(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x3: // sltiu instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::SLTIU(rd.get_value(), rs1.get_value(), imm, state);
            break;
        default:
            return -1;
            break;
        }
        break;


        
    default:
        return -1;
    }

}

// R-type Instruction add: rd = rs1 + rs2
int Gen_State::ADD(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 + val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction sub: rd = rs1 - rs2
int Gen_State::SUB(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 - val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction xor: rd = rs1 ^ rs2
int Gen_State::XOR(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 ^ val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction or: rd = rs1 | rs2
int Gen_State::OR(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 | val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction or: rd = rs1 & rs2
int Gen_State::AND(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 & val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction sll: rd = rs1 << rs2
int Gen_State::SLL(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 << val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction srl: rd = rs1 >> rs2
int Gen_State::SRL(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1 >> val_rs2;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction sra: rd = rs1 >> rs2
int Gen_State::SRA(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = val_rs1.SRA(val_rs2);

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction slt: rd = (rs1 < rs2) ? 1 : 0
int Gen_State::SLT(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = (static_cast<int>(val_rs1.get_value()) < static_cast<int>(val_rs2.get_value())) ? Word{1} : Word{0};

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// R-type Instruction sltu: rd = (rs1 < rs2) ? 1 : 0
int Gen_State::SLTU(unsigned int rd, unsigned int rs1, unsigned int rs2, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rs2 = state.get_value_in_state(REGISTER, rs2);
    Word val_rd = (val_rs1 < val_rs2) ? Word{1} : Word{0};

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction addi: rd = rs1 + imm
int Gen_State::ADDI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 + imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction xori: rd = rs1 ^ imm
int Gen_State::XORI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 ^ imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction ori: rd = rs1 ^ imm
int Gen_State::ORI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 | imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction andi: rd = rs1 & imm
int Gen_State::ANDI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 & imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction slli: rd = rs1 << imm[0:4]
int Gen_State::SLLI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 << imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction srli: rd = rs1 >> imm[0:4]
int Gen_State::SRLI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1 >> imm;

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction srai: rd = rs1 >> imm[0:4]
int Gen_State::SRAI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = val_rs1.SRA(imm);

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction slti: rd = (rs1 < imm) ? 1 : 0
int Gen_State::SLTI(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = (static_cast<int>(val_rs1.get_value()) < static_cast<int>(imm.get_value())) ? Word{1} : Word{0};

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// I-type Instruction sltiu: rd = (rs1 < imm) ? 1 : 0
int Gen_State::SLTIU(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = (val_rs1 < imm) ? Word{1} : Word{0};

    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}
