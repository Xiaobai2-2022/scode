#include "construct_risc_v.hpp"

// Constructs Risc-V assembly 0 command to binary code by reading file and output
//     if_name is the input file name
//     of_name is the output file name
bool Ctor_RV::rv_assembly0_to_bin(std::string if_name, std::string of_name) {

    bool no_error{true};

    // For error checking usage
    ulong count{1};

    // Attempt to open input and output file
    std::ifstream fin(if_name);
    std::ofstream fout(of_name);
    
    // Check if the input file failed to open
    if(!fin.is_open()) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Error opening the input file: " << if_name << "." << std::endl;
        return false;
    }
    // Check if the output file failed to open
    if(!fout.is_open()) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Error opening the output file: " << of_name << "." << std::endl;
        return false;
    }

    std::string cur_line;
    std::getline(fin, cur_line);

    // Check if the risc-v assembly file is of the correct type
    if(!Utility::is_start_with(cur_line, "SCode Assembly 0")) {
        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
        std::cout << "Input file has the wrong type: " << if_name << "." << std::endl;
        return false;
    }

    // Output the SCode header
    fout << "SCode Binary, Generated By Ctor_RV." << std::endl;

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        count++;

        std::string inst;

        int rd, rs1, rs2;       // reg inputs
        int imm;                // immediate
        int pi, po;             // io ports

        std::pair<Word, int> generate_output;

        // Construct the string stream to access all elements on the line
        std::stringstream ss_line{cur_line};
        
        // Read the instruction
        ss_line >> inst;

        // Attempt to find the instruction in map
        auto it = Utility::inst.find(inst);

        if(it != Utility::inst.end()) {
            int inst_code = it->second;

            switch (inst_code) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: // Case R Type Instructions
                // Input rd, rs1, rs2 and generate code
                if(ss_line >> rd >> rs1 >> rs2) {
                    switch (inst_code) {
                    case 0: // case add
                        generate_output = Gen_Code::ADD(rd, rs1, rs2);
                        break;
                    case 1: // case sub
                        generate_output = Gen_Code::SUB(rd, rs1, rs2);
                        break;
                    case 2: // case xor
                        generate_output = Gen_Code::XOR(rd, rs1, rs2);
                        break;
                    case 3: // case or
                        generate_output = Gen_Code::OR(rd, rs1, rs2);
                        break;
                    case 4: // case and
                        generate_output = Gen_Code::AND(rd, rs1, rs2);
                        break;
                    case 5: // case sll
                        generate_output = Gen_Code::SLL(rd, rs1, rs2);
                        break;
                    case 6: // case srl
                        generate_output = Gen_Code::SRL(rd, rs1, rs2);
                        break;
                    case 7: // case sra
                        generate_output = Gen_Code::SRA(rd, rs1, rs2);
                        break;
                    case 8: // case slt
                        generate_output = Gen_Code::SLT(rd, rs1, rs2);
                        break;
                    case 9: // case sltu
                        generate_output = Gen_Code::SLTU(rd, rs1, rs2);
                        break;
                    }

                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "R Type Instruction should have format: \"cmd rd rs1 rs2\".");
                    no_error = false;
                }
                break;

            case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: // Case I type instructions (1st part)
            case 19: case 20: case 21: case 22: case 23: // Case I type instructions (2nd part)
            case 34: // Case I type instructions (3rd part)
                // Input rd, rs1, imm and generate code
                if(ss_line >> rd >> rs1 >> imm) {
                    switch (inst_code) {
                    case 10: // case addi
                        generate_output = Gen_Code::ADDI(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 11: // case xori
                        generate_output = Gen_Code::XORI(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 12: // case ori
                        generate_output = Gen_Code::ORI(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 13: // case andi
                        generate_output = Gen_Code::ANDI(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 14: // case slli
                        generate_output = Gen_Code::SLLI(rd, rs1, Utility::change_length_unsigned(imm, 5));
                        break;
                    case 15: // case srli
                        generate_output = Gen_Code::SRLI(rd, rs1, Utility::change_length_unsigned(imm, 5));
                        break;
                    case 16: // case srai
                        generate_output = Gen_Code::SRAI(rd, rs1, Utility::change_length_unsigned(imm, 5));
                        break;
                    case 17: // case slti
                        generate_output = Gen_Code::SLTI(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 18: // case sltiu
                        generate_output = Gen_Code::SLTIU(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    
                    case 19: // case lb
                        generate_output = Gen_Code::LB(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 20: // case lh
                        generate_output = Gen_Code::LH(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 21: // case lw
                        generate_output = Gen_Code::LW(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 22: // case lbu
                        generate_output = Gen_Code::LBU(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 23: // case lhu
                        generate_output = Gen_Code::LHU(rd, rs1, Utility::change_length(imm, 12));
                        break;
                    case 34: // case jalr
                        generate_output = Gen_Code::JALR(rd, rs1, Utility::change_length(imm, 12));
                    }
                    
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "I Type Instruction should have format: \"cmd rd rs1 imm\".");
                    no_error = false;
                }
                break;

            case 24: case 25: case 26: // Case S type instructions
                // Input rd, rs1, imm and generate code
                if(ss_line >> rs1 >> rs2 >> imm) {
                    switch (inst_code) {
                    case 24: // case sb
                        generate_output = Gen_Code::SB(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 25: // case sh
                        generate_output = Gen_Code::SH(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 26: // case sw
                        generate_output = Gen_Code::SW(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    }
                    
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "S Type Instruction should have format: \"cmd rs1 rs2 imm\".");
                    no_error = false;
                }
                break;

            case 27: case 28: case 29: case 30: case 31: case 32: // Case B type instructions
                // Input rs1, rs2, imm and generate code
                if(ss_line >> rs1 >> rs2 >> imm) {
                    switch (inst_code) {
                    case 27: // case beq
                        generate_output = Gen_Code::BEQ(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 28: // case bne
                        generate_output = Gen_Code::BNE(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 29: // case blt
                        generate_output = Gen_Code::BLT(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 30: // case bge
                        generate_output = Gen_Code::BGE(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 31: // case bltu
                        generate_output = Gen_Code::BLTU(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    case 32: // case bgeu
                        generate_output = Gen_Code::BGEU(rs1, rs2, Utility::change_length(imm, 12));
                        break;
                    }

                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "B Type Instruction should have format: \"cmd rs1 rs2 imm\".");
                    no_error = false;
                }
                break;

            case 33: // Case J type instructions
                // Input rd, imm and generate code
                if(ss_line >> rd >> imm) {
                    switch (inst_code) {
                    case 33: // case jal
                        generate_output = Gen_Code::JAL(rd, Utility::change_length(imm, 20));
                        break;
                    }
                    
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "J Type Instruction should have format: \"cmd rd imm\".");
                    no_error = false;
                }
                break;

            case 35: case 36: // Case U type instructions
                // Input rd, imm and generate code
                if(ss_line >> rd >> imm) {
                    switch (inst_code) {
                    case 35: // case lui
                        generate_output = Gen_Code::LUI(rd, Utility::change_length(imm, 20));
                        break;
                    case 36: // case auipc
                        generate_output = Gen_Code::AUIPC(rd, Utility::change_length(imm, 20));
                        break;
                    }
                    
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "J Type Instruction should have format: \"cmd rd imm\".");
                    no_error = false;
                }
                break;

            case 50: case 51: case 52: case 53: case 54: case 55: case 56: case 57: // Case R (RV32M) type instructions
                // Input rd, rs1, rs2 and generate code
                if(ss_line >> rd >> rs1 >> rs2) {
                    switch (inst_code) {
                    case 50: // case mul
                        generate_output = Gen_Code::MUL(rd, rs1, rs2);
                        break;
                    case 51: // case mulh
                        generate_output = Gen_Code::MULH(rd, rs1, rs2);
                        break;
                    case 52: // case mulsu
                        generate_output = Gen_Code::MULSU(rd, rs1, rs2);
                        break;
                    case 53: // case mulu
                        generate_output = Gen_Code::MULU(rd, rs1, rs2);
                        break;
                    case 54: // case div
                        generate_output = Gen_Code::DIV(rd, rs1, rs2);
                        break;
                    case 55: // case divu
                        generate_output = Gen_Code::DIVU(rd, rs1, rs2);
                        break;
                    case 56: // case rem
                        generate_output = Gen_Code::REM(rd, rs1, rs2);
                        break;
                    case 57: // case remu
                        generate_output = Gen_Code::REMU(rd, rs1, rs2);
                        break;
                    }
                    
                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                } else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "R (RV32M) Type Instruction should have format: \"cmd rd rs1 rs2\".");
                    no_error = false;
                }
                break;
            
            case 900:
                generate_output = Gen_Code::END();
                fout << generate_output.first << std::endl;
                break;

            case 901:
                generate_output = Gen_Code::NOP();
                fout << generate_output.first << std::endl;
                break;

            case 902:
                // Input pi, rd and generate code
                if(ss_line >> pi >> rd) {
                    generate_output = Gen_Code::INPUT(pi, rd);

                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    }else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                }else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "Input (SCode) Instruction should have format: \"input pi rd\".");
                    no_error = false;
                }
                break;

            case 903:
                // Input po, rs1 and generate code
                if(ss_line >> po >> rs1) {
                    generate_output = Gen_Code::OUTPUT(po, rs1);

                    if(generate_output.second == 0) {
                        fout << generate_output.first << std::endl;
                    }else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                        Error_Out::out_error(generate_output.second, count, "");
                        no_error = false;
                    }
                }else {
                    fout << "!!! Error line !!!" << std::endl;
                    std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
                    Error_Out::out_error(102, count, "Output (SCode) Instruction should have format: \"output po, rs1\".");
                    no_error = false;
                }
                break;
                
            default:
                break;
            }

        } else {
            fout << "!!! Error line !!!" << std::endl;
            std::cout << "Error constructing rv assembly 0 to binary." << std::endl;
            Error_Out::out_error(101, count, inst);
            no_error = false;
        }

    }

    return no_error;

}

// Constructs Risc-V assembly 1 command to Risc-V assembly 0 command by reading file and output
//     if_name is the input file name
//     of_name is the output file name
bool Ctor_RV::rv_assembly1_to_assembly0(std::string if_name, std::string of_name) {

    bool no_error{true};

    // For error checking usage
    ulong count{1};

    // symbol table
    std::unordered_map<std::string, long> symbol_table;

    // Attempt to open input and output file
    std::ifstream fin(if_name);
    std::ofstream fout(of_name);
    
    // Check if the input file failed to open
    if(!fin.is_open()) {
        std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
        std::cout << "Error opening the input file: " << if_name << "." << std::endl;
        return false;
    }
    // Check if the output file failed to open
    if(!fout.is_open()) {
        std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
        std::cout << "Error opening the output file: " << of_name << "." << std::endl;
        return false;
    }

    std::string cur_line;
    std::getline(fin, cur_line);

    // Check if the risc-v assembly file is of the correct type
    if(!Utility::is_start_with(cur_line, "SCode Assembly 1")) {
        std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
        std::cout << "Input file has the wrong type: " << if_name << "." << std::endl;
        return false;
    }

    /***************
     * First Pass  *
     ***************/

    long pc{0};    // pc value

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        count++;

        std::string inst;
        
        std::string symbol;     // symbol in the table

        std::pair<Word, int> generate_output;

        // Construct the string stream to access all elements on the line
        std::stringstream ss_line{cur_line};
        
        // Read the instruction
        ss_line >> inst;

        // Attempt to find the instruction in map
        auto it = Utility::inst.find(inst);

        if(it != Utility::inst.end()) {
            int inst_code = it->second;

            switch (inst_code) {
            case 1000: // case comment
                /* Does nothing */
                break;
            case 1001: // case define
                // Input symbol and compute symbol table
                if(ss_line >> symbol) {
                    // Search for the instructions in the symbol table
                    auto itr1 = symbol_table.find(symbol);
                    if(itr1 != symbol_table.end()) {
                        std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
                        Error_Out::out_error(201, count, symbol);
                        no_error = false;
                    } else {
                        // Search for the instruction in the instruction table
                        auto itr2 = Utility::inst.find(symbol);
                        if(itr2 != Utility::inst.end()) {
                            std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
                            Error_Out::out_error(202, count, symbol);
                            no_error = false;
                        } else {
                            symbol_table.insert({symbol, pc});
                        }
                    }
                } else {
                    std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
                    Error_Out::out_error(102, count, "Define Instruction should have format: \"define symbol\".");
                    no_error = false;
                }
                break;
                
            default: // case all other commands, add pc counter by 4.
                pc += 4;
                break;
            }
            fout << cur_line << std::endl;
        } else {
            fout << "!!! Error line !!!" << std::endl;
            std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
            Error_Out::out_error(101, count, inst);
            no_error = false;
        }

    }

    if(!no_error) {
        return no_error;
    }

    /***************
     * Second Pass *
     ***************/

    // Clears the fout file
    fout.close();
    fout.open(of_name);

    // Output the SCode header
    fout << "SCode Assembly 0, Generated By Ctor_RV." << std::endl;

    count = 1;
    pc = 0;

    // Clear and reset the file pointer to the begining
    fin.clear();
    fin.seekg(0, std::ios::beg);
    std::getline(fin, cur_line);

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        count++;

        std::string inst;

        int rd, rs1, rs2;       // reg inputs
        int imm;                // immediate
        std::string symbol;     // symbol in the table

        // Construct the string stream to access all elements on the line
        std::stringstream ss_line{cur_line};
        
        // Read the instruction
        ss_line >> inst;

        // Attempt to find the instruction in map
        auto it = Utility::inst.find(inst);

        if(it != Utility::inst.end()) {
            int inst_code = it->second;

            switch (inst_code) {
            case 1000: // Case comment
                /* Does nothing */
                break;
            case 1001: // Case define
                /* Does nothing */
                break;
                
            case 27: case 28: case 29: case 30: case 31: case 32: // Case B type instructions
                // Input rs1, rs2, imm and generate code
                if(ss_line >> rs1 >> rs2 >> imm) {
                    /* Do nothing for the compiled code */
                } else {
                    // Reset the string stream
                    ss_line.clear();
                    ss_line.str(cur_line);
                    ss_line >> inst;
                    if(ss_line >> rs1 >> rs2 >> symbol) {
                        // Attempt to find symbol in symbol table
                        auto itr = symbol_table.find(symbol);
                        if(itr != symbol_table.end()) {
                            long cur_pc = pc + 4;
                            cur_pc = itr->second - cur_pc;
                            cur_pc /= 2;
                            fout << it->first << " " << rs1 << " " << rs2 << " " << cur_pc << std::endl;
                        } else {
                            fout << "!!! Error line !!!" << std::endl;
                            std::cout << "Error constructing rv assembly 1 to rv assembly 0." << std::endl;
                            Error_Out::out_error(102, count, "B Type Instruction should have format: \"cmd rs1 rs2 label\".");
                        }
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 1 to rv assembly 0." << std::endl;
                        Error_Out::out_error(203, count, symbol);
                        no_error = false;
                    }
                }
                pc += 4;
                break;
            
            case 33: // Case J type instructions
                // Input rs1, rs2, imm and generate code
                if(ss_line >> rd >> imm) {
                    /* Do nothing for the compiled code */
                } else {
                    // Reset the string stream
                    ss_line.clear();
                    ss_line.str(cur_line);
                    ss_line >> inst;
                    if(ss_line >> rd >> symbol) {
                        // Attempt to find symbol in symbol table
                        auto itr = symbol_table.find(symbol);
                        if(itr != symbol_table.end()) {
                            long cur_pc = pc + 4;
                            cur_pc = itr->second - cur_pc;
                            cur_pc /= 2;
                            fout << it->first << " " << rd << " " << cur_pc << std::endl;
                        } else {
                            fout << "!!! Error line !!!" << std::endl;
                            std::cout << "Error constructing rv assembly 1 to rv assembly 0." << std::endl;
                            Error_Out::out_error(102, count, "J Type Instruction should have format: \"cmd rs1 label\".");
                        }
                    } else {
                        fout << "!!! Error line !!!" << std::endl;
                        std::cout << "Error constructing rv assembly 1 to rv assembly 0." << std::endl;
                        Error_Out::out_error(203, count, symbol);
                        no_error = false;
                    }
                }
                pc += 4;
                break;
                
            default: // case all other commands, add pc counter by 4.
                fout << cur_line << std::endl;
                pc += 4;
                break;
            }
        } else {
            fout << "!!! Error line !!!" << std::endl;
            std::cout << "Error constructing rv assembly 1 to assembly 0." << std::endl;
            Error_Out::out_error(101, count, inst);
            no_error = false;
        }

    }

    return no_error;

}
