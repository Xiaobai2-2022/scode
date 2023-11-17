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


    
    case 0b0000011: // Case I-type instruction with opcode 0000011
    
        // Read the function3 from the memory
        funct3 = mem_at_pc.limit(14, 12);

        // Read the registers from the memory
        rd = mem_at_pc.limit(11, 7);
        rs1 = mem_at_pc.limit(19, 15);

        switch (funct3.get_value()) {
        case 0x0: // lb instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::LB(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x1: // lh instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::LH(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x2: // lw instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::LW(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x4: // lbu instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::LBU(rd.get_value(), rs1.get_value(), imm, state);
            break;
        case 0x5: // lh instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::LHU(rd.get_value(), rs1.get_value(), imm, state);
            break;
        default:
            return -1;
            break;
        }
        break;



    case 0b1100111: // Case I-type instruction with opcode 1100111
    
        // Read the function3 from the memory
        funct3 = mem_at_pc.limit(14, 12);

        // Read the registers from the memory
        rd = mem_at_pc.limit(11, 7);
        rs1 = mem_at_pc.limit(19, 15);

        switch (funct3.get_value()) {
            case 0x0: // jalr instruction
            // Read the imm from the memory
            imm = mem_at_pc.extend(31, 20);
            return Gen_State::JALR(rd.get_value(), rs1.get_value(), imm, state);
            break;
        default:
            return -1;
            break;
        }
        break;



    case 0b0100011: // Case S-type instruction with opcode 0100011
    
        // Read the function3 from the memory
        funct3 = mem_at_pc.limit(14, 12);

        // Read the registers from the memory
        rs1 = mem_at_pc.limit(19, 15);
        rs2 = mem_at_pc.limit(24, 20);

        switch (funct3.get_value()) {
            case 0x0: // sb instruction
            // Read the imm from the memory
            imm = (mem_at_pc.limit(31, 25) << 5) + mem_at_pc.limit(11, 7);
            imm = imm.extend(11);
            return Gen_State::SB(rs1.get_value(), rs2.get_value(), imm, state);
            break;
            case 0x1: // sh instruction
            // Read the imm from the memory
            imm = (mem_at_pc.limit(31, 25) << 5) + mem_at_pc.limit(11, 7);
            imm = imm.extend(11);
            return Gen_State::SH(rs1.get_value(), rs2.get_value(), imm, state);
            break;
            case 0x2: // sw instruction
            // Read the imm from the memory
            imm = (mem_at_pc.limit(31, 25) << 5) + mem_at_pc.limit(11, 7);
            imm = imm.extend(11);
            return Gen_State::SW(rs1.get_value(), rs2.get_value(), imm, state);
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

// I-type Instruction lb: rd = M[rs + imm][0 : 7]
int Gen_State::LB(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = Word{};

    // Find the address
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + static_cast<unsigned long>(static_cast<int>(imm.get_value()));

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;
        
        val_rd = state.get_value_in_state(MEMORY, word_address);

        switch (byte_address) {
        case 0:
            val_rd = val_rd.extend(31, 24);
            break;
        case 1:
            val_rd = val_rd.extend(23, 16);
            break;
        case 2:
            val_rd = val_rd.extend(15, 8);
            break;
        case 3:
            val_rd = val_rd.extend(7);
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});
        return 0;

    } else {
        return -2;
    }

}

// I-type Instruction lh: rd = M[rs + imm][0 : 15]
int Gen_State::LH(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = Word{};

    // Find the address
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + (static_cast<unsigned long>(static_cast<int>(imm.get_value())) * 2);

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;
        
        val_rd = state.get_value_in_state(MEMORY, word_address);

        switch (byte_address) {
        case 0:
            val_rd = val_rd.extend(31, 16);
            break;
        case 2:
            val_rd = val_rd.extend(15);
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});
        return 0;

    } else {
        return -2;
    }

}

// I-type Instruction lw: rd = M[rs + imm]
int Gen_State::LW(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = Word{};

    // Find the address
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + (static_cast<unsigned long>(static_cast<int>(imm.get_value())) * 4);

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;
        
        val_rd = state.get_value_in_state(MEMORY, word_address);

        state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});
        return 0;

    } else {
        return -2;
    }

}

// I-type Instruction lbu: rd = M[rs + imm][0 : 7]
int Gen_State::LBU(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = Word{};

    // Find the address
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + static_cast<unsigned long>(static_cast<int>(imm.get_value()));

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;
        
        val_rd = state.get_value_in_state(MEMORY, word_address);

        switch (byte_address) {
        case 0:
            val_rd = val_rd.limit(31, 24);
            break;
        case 1:
            val_rd = val_rd.limit(23, 16);
            break;
        case 2:
            val_rd = val_rd.limit(15, 8);
            break;
        case 3:
            val_rd = val_rd.limit(7);
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});
        return 0;

    } else {
        return -2;
    }

}

// I-type Instruction lhu: rd = M[rs + imm][0 : 15]
int Gen_State::LHU(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    // Update the value in RD
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    Word val_rd = Word{};

    // Find the address
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + (static_cast<unsigned long>(static_cast<int>(imm.get_value())) * 2);

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;
        
        val_rd = state.get_value_in_state(MEMORY, word_address);

        switch (byte_address) {
        case 0:
            val_rd = val_rd.limit(31, 16);
            break;
        case 2:
            val_rd = val_rd.limit(15);
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});
        return 0;

    } else {
        return -2;
    }

}

// I-type Instruction jalr: rd = PC + 4; PC = rs1 + imm
int Gen_State::JALR(unsigned int rd, unsigned int rs1, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rd, 1, 31)) return 1;
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;

    unsigned long pc;
    unsigned long cur_pc = state.get_pc();
    Word val_rd = Word{0};

    // PC = rs1 + imm
    pc = static_cast<unsigned long>(state.get_value_in_state(REGISTER, rs1).get_value());
    pc += static_cast<unsigned long>(static_cast<int>(imm.get_value()));
    pc *= 4;

    if(pc <= 0x3ffffffff) {
        state.set_pc(pc);
    } else {
        return -2;
    }

    // rd = PC + 4, since pc is pre-incremented, it is not required to increment it here
    cur_pc /= 4;
    val_rd = Word{static_cast<unsigned int>(cur_pc)};
    state.set_value_in_to_state(Cell{REGISTER, rd, val_rd});

    return 0;

}

// S-type Instruction sb: M[rs + imm][0 : 7] = rs2[0 : 7]
int Gen_State::SB(unsigned int rs1, unsigned int rs2, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    Word val_mem = Word{};

    // Find the address
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + static_cast<unsigned long>(static_cast<int>(imm.get_value()));

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;

        // Extracts the last 8 digits in rs2
        val_mem = state.get_value_in_state(REGISTER, rs2).limit(7);

        switch (byte_address) {
        case 0:
            val_mem <<= 24;
            break;
        case 1:
            val_mem <<= 16;
            break;
        case 2:
            val_mem <<= 8;
            break;
        case 3:
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{MEMORY, word_address, val_mem});
        return 0;

    } else {
        return -2;
    }

}

// S-type Instruction sh: M[rs + imm][0 : 15] = rs2[0 : 15]
int Gen_State::SH(unsigned int rs1, unsigned int rs2, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    Word val_mem = Word{};

    // Find the address
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + (static_cast<unsigned long>(static_cast<int>(imm.get_value())) * 2);

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;

        // Extracts the last 16 digits in rs2
        val_mem = state.get_value_in_state(REGISTER, rs2).limit(15);

        switch (byte_address) {
        case 0:
            val_mem <<= 16;
            break;
        case 2:
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{MEMORY, word_address, val_mem});
        return 0;

    } else {
        return -2;
    }

}

// S-type Instruction sw: M[rs + imm][0 : 31] = rs2[0 : 31]
int Gen_State::SW(unsigned int rs1, unsigned int rs2, Word imm, State &state) {

    // Check if all registers are in range
    if(!Utility::is_in_range(rs1, 0, 31)) return 2;
    if(!Utility::is_in_range(rs2, 0, 31)) return 3;

    Word val_mem = Word{};

    // Find the address
    Word val_rs1 = state.get_value_in_state(REGISTER, rs1);
    unsigned long word_address = static_cast<unsigned long>(val_rs1.get_value());
    word_address *= 4;
    unsigned long byte_address = word_address + (static_cast<unsigned long>(static_cast<int>(imm.get_value())) * 4);

    // Check if the address is in range
    if(byte_address <= 0x3ffffffff) {
        word_address = byte_address / 4 * 4;
        byte_address = byte_address % 4;

        // Extracts the last 32 digits in rs2
        val_mem = state.get_value_in_state(REGISTER, rs2);

        switch (byte_address) {
        case 0:
            break;
        default:
            return -1000;
            break;
        }

        state.set_value_in_to_state(Cell{MEMORY, word_address, val_mem});
        return 0;

    } else {
        return -2;
    }

}
