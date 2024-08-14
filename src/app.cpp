#include "app_interface.hpp"

void init();
int main();

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    Sys_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

    // Clean up the environment
    // Sys_Util::clean_repo();
    Sys_Util::clear_terminal();
    SLog::clean();

    // Displays message
    Sys_Util::display_sc_msg();

    // Sets the log file name
    SLog::set_file_name("svm_prod_1.slog");

}

int main() {

    // Set the environment to initial state
    init();

    bool e_flag{false};
    bool s_flag{false};

    // The name of the binary file generated
    std::string bin_name{"sca_bin_001.scg"};

    // Try to assemble the file
    if(Sys_Util::assemble_file(bin_name) != 0) {
        return -1;
    }

    SVM s{bin_name};
    s_flag = true;

    std::string cur_line;
    std::string scanner;

    std::cout << SStyle::GREEN << std::endl << std::endl << SStyle::PREV_LINE << SStyle::PREV_LINE << "\rSVM > " << SStyle::NC;

    Sys_Util::flush_cin();

    while(std::getline(std::cin, cur_line)) {
    
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
                Sys_Util::clear_terminal();
                s.print();
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
            }
            e_flag = false;
            SVM::clear();
            std::cout << SStyle::GREEN << "SVM > " << SStyle::NC;
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
                if(!s_flag) {
                    Sys_Util::clear_terminal();
                    Sys_Util::display_sc_msg();
                    std::cout << SStyle::RED
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
                if(!s_flag) {
                    Sys_Util::clear_terminal();
                    Sys_Util::display_sc_msg();
                    std::cout << SStyle::RED
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
