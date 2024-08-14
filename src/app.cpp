#include "app_interface.hpp"

void init();
int main();

void init() {

    // Get the size of the terminal
    // std::pair<unsigned int, unsigned int> terminal_size;
    // Sys_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

    // Clean up the environment
    // Sys_Util::clean_repo();
    SLog::clean();

    // Displays message
    SVM::clear();

    // Sets the log file name
    SLog::set_file_name("svm_prod_1.slog");

}

int main() {

    // Set the environment to initial state
    init();

    bool e_flag{false};

    // The name of the binary file generated
    std::string bin_name{"sca_bin_001.scg"};

    // // Try to assemble the file
    // if(Sys_Util::assemble_file(bin_name) != 0) {
    //     return -1;
    // }

    SVM s{};

    std::string cur_line;
    std::string scanner;

    std::cout << SStyle::GREEN << std::endl << std::endl << SStyle::PREV_LINE << SStyle::PREV_LINE << "\rSVM > " << SStyle::NC;

    // Sys_Util::flush_cin();

    while(std::getline(std::cin, cur_line)) {
        
        // std::cout << cur_line << std::endl;
    
        std::vector<std::string> args;

        std::stringstream ss_line{cur_line};

        while(ss_line >> scanner) {
            args.emplace_back(scanner);
        }

        // No instruction
        if(args.size() == 0) {
            std::cout << SStyle::GREEN << SStyle::PREV_LINE << "\rSVM > " << SStyle::NC;
        }
    

        
        // Quit
        else if(args.at(0) == "quit") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                e_flag = false;
                SLog::log("Program terminated by user.");
                Sys_Util::clear_terminal();
                break;
            }
        }
        

        
        // Help
        else if(args.at(0) == "help") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                e_flag = false;
                SVM::display_help_msg();
                SVM::clear();
                if(s.is_valid()) {
                    s.print();
                }
            }
        }
        
        
        
        // Clear
        else if(args.at(0) == "clear") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                e_flag = false;
                SVM::clear();
                std::cout << SStyle::GREEN << "SVM > " << SStyle::NC;
            }
        }



        // List
        else if(args.at(0) == "list") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                e_flag = false;
                SVM::display_files();
                std::cout << SStyle::GREEN << "SVM > " << SStyle::NC;
            }
        }
    

        
        // Display
        else if(args.at(0) == "display") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                if(s.is_valid()) {
                    s.print();
                    e_flag = false;
                } else {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    std::cout << SStyle::RED << SStyle::PREV_LINE
                        << "\rInternal error SVM-Prod-1-0012, cannot display, please enter a different instruction." 
                        << SStyle::NC << std::endl;
                    SLog::log("Internal error SVM-Prod-1-0012, no state is detected.");
                    e_flag = true;
                }
            }
        }



        // SC
        else if(args.at(0) == "sc") {
            if(args.size() < 2) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0014, too few arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0014, too few arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else if(args.size() > 3) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else if(args.size() == 2) {
                unsigned int e_code = Sys_Util::conversion(args.at(1), bin_name);
                if(e_code) {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    if(e_code == 5) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE
                            << "\rInternal error SVM-Prod-1-0005, required file does not open." 
                            << SStyle::NC << std::endl;
                    } else if(e_code == 6) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE
                            << "\rInternal error SVM-Prod-1-0006, required file is empty." 
                            << SStyle::NC << std::endl;
                    } else if(e_code == 4) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0004, failed to convert from RV Assembly 1 to RV Assembly 0." << SStyle::NC << std::endl;
                    } else if(e_code == 7) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0007, failed to convert from RV Assembly 0 to RV Binary." << SStyle::NC << std::endl;
                    } else if(e_code == 8) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0008, file format not recognized as any of the SCode assembly products." << SStyle::NC << std::endl;
                    } else {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Unknown Error." << SStyle::NC << std::endl;
                    }
                    e_flag = true;
                } else {
                    e_flag = false;
                }
            } else {
                bin_name = args.at(2);
                unsigned int e_code = Sys_Util::conversion(args.at(1), bin_name);
                if(e_code) {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    if(e_code == 5) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE
                            << "\rInternal error SVM-Prod-1-0005, required file does not open." 
                            << SStyle::NC << std::endl;
                    } else if(e_code == 6) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE
                            << "\rInternal error SVM-Prod-1-0006, required file is empty." 
                            << SStyle::NC << std::endl;
                    } else if(e_code == 4) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0004, failed to convert from RV Assembly 1 to RV Assembly 0." << SStyle::NC << std::endl;
                    } else if(e_code == 7) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0007, failed to convert from RV Assembly 0 to RV Binary." << SStyle::NC << std::endl;
                    } else if(e_code == 8) {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Internal error SVM-Prod-1-0008, file format not recognized as any of the SCode assembly products." << SStyle::NC << std::endl;
                    } else {
                        std::cout << SStyle::RED << SStyle::PREV_LINE 
                            << "Unknown Error." << SStyle::NC << std::endl;
                    }
                    e_flag = true;
                } else {
                    e_flag = false;
                }
            }
        }



        // Create
        else if(args.at(0) == "create") {
            // SVM::clear();
            if(args.size() > 2) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else if(args.size() == 1) {
                s = SVM{bin_name};;
                if(s.is_valid()) {
                    e_flag = false;
                } else {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    std::cout << SStyle::RED << SStyle::PREV_LINE
                        << "\rInternal error SVM-Prod-1-0015, an error has occured during state generation." 
                        << SStyle::NC << std::endl;
                    e_flag = true;
                }
            } else {
                bin_name = args.at(1);
                s = SVM{bin_name};
                if(s.is_valid()) {
                    e_flag = false;
                } else {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    std::cout << SStyle::RED << SStyle::PREV_LINE
                        << "\rInternal error SVM-Prod-1-0015, an error has occured during state generation." 
                        << SStyle::NC << std::endl;
                    e_flag = true;
                }
            }
        }
        
        
        
        // Update
        else if(args.at(0) == "update") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                if(!s.is_valid()) {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    std::cout << SStyle::RED << SStyle::PREV_LINE
                        << "\rInternal error SVM-Prod-1-0012, cannot update, please enter a different instruction." 
                        << SStyle::NC << std::endl;
                    SLog::log("Internal error SVM-Prod-1-0012, no state is detected.");
                    e_flag = true;
                } else {
                    e_flag = false;
                    int res = s.update();
                    if(res) {
                        if(res == -99) {
                            s.print();
                            std::cout << SStyle::GREEN <<
                                "=========================== Program finished ===========================" << SStyle::NC << std::endl << std::endl;
                        } else {
                            if(e_flag) {
                                std::cout << SStyle::PREV_LINE;
                            }
                            std::cout << SStyle::RED << SStyle::PREV_LINE
                                << "\rInternal error SVM-Prod-1-0011, cannot update, please enter a different instruction." 
                                << SStyle::NC << std::endl;
                            SLog::log("Internal error SVM-Prod-1-0011, cannot update the current state.");
                            e_flag = true;
                        }
                    }
                }
            }
        }
        
        
        
        // Undo
        else if(args.at(0) == "undo") {
            if(args.size() > 1) {
                if(e_flag) {
                    std::cout << SStyle::PREV_LINE;
                }
                std::cout << SStyle::RED << SStyle::PREV_LINE
                    << "\rInternal error SVM-Prod-1-0013, too many arguments, please enter a different instruction." 
                    << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0013, too many arguments for command " + args.at(0) + ".");
                e_flag = true;
            } else {
                if(!s.is_valid()) {
                    if(e_flag) {
                        std::cout << SStyle::PREV_LINE;
                    }
                    std::cout << SStyle::RED << SStyle::PREV_LINE
                        << "\rInternal error SVM-Prod-1-0012, cannot undo, please enter a different instruction." 
                        << SStyle::NC << std::endl;
                    SLog::log("Internal error SVM-Prod-1-0012, no state is detected.");
                    e_flag = true;
                } else {
                    if(!s.undo()) {
                        if(e_flag) {
                            std::cout << SStyle::PREV_LINE;
                        }
                        std::cout << SStyle::RED << SStyle::PREV_LINE
                            << "\rInternal error SVM-Prod-1-0009, nothing to undo, please enter a different instruction." 
                            << SStyle::NC << std::endl;
                        SLog::log("Internal error SVM-Prod-1-0009, cannot undo the initial state.");
                        e_flag = true;
                    } else {
                        e_flag = false;
                    }
                }
            }
        } 
        
        
        
        // Wrong Instruction
        else {

            if(e_flag) {
                std::cout  << SStyle::PREV_LINE;
            }

            std::cout.flush();
            // Sys_Util::flush_cin();
            std::cout << SStyle::RED << SStyle::PREV_LINE
                << "\rInternal error SVM-Prod-1-0010, \"" << args.at(0)  << "\" is not a valid instruction, please enter a valid instruction." 
                << SStyle::NC << std::endl;
            SLog::log("Internal error SVM-Prod-1-0010, instruction \"" + args.at(0) + "\" is not a valid instruction.");

            e_flag = true;

        }

        if(!e_flag) {
            std::cout << SStyle::GREEN << std::endl << std::endl << SStyle::PREV_LINE << SStyle::PREV_LINE << "\rSVM > " << SStyle::NC;
        } else {
            std::cout << SStyle::GREEN << std::endl << SStyle::PREV_LINE << "\rSVM > " << SStyle::NC;
        }

    }

    Sys_Util::display_sc_msg();
    std::cout << SStyle::YELLOW << "Program terminated, press enter to continue..." << SStyle::NC;
 
    std::string temp;
    std::getline(std::cin, temp);

    Sys_Util::clear_terminal();

    return 0;

}
