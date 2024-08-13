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

    // The name of the binary file generated
    std::string bin_name{"sca_bin_001.scg"};

    // Try to assemble the file
    if(Sys_Util::assemble_file(bin_name) != 0) {
        return -1;
    }

    SVM s(bin_name);

    std::string cmd;
    
    std::cout << SStyle::GREEN << "Please enter an instruction: " << SStyle::NC;
    while(std::cin >> cmd) {

        if(cmd == "quit") {
            SLog::log("Program terminated by user.");
            Sys_Util::clear_terminal();
            break;
        } else if(cmd == "help") {

            Sys_Util::display_help_msg();

            Sys_Util::flush_cin();
            std::cin.get();

            Sys_Util::clear_terminal();
            s.print();

        }else if(cmd == "update") {
            if(!s.update()) break;
        } else if(cmd == "undo") {
            if(!s.undo()) continue;
        } else {

            std::cout.flush();
            Sys_Util::flush_cin();
            std::cout << SStyle::RED << "\033[F\033[2K\rInternal error SVM-Prod-1-0010, \"" << cmd << "\" is not a valid instruction, please enter a valid instruction: " << SStyle::NC;
            SLog::log("Internal error SVM-Prod-1-0010, instruction \"" + cmd + "\" is not a valid instruction.");
            continue;

        }


        Sys_Util::flush_cin();
        std::cout << SStyle::GREEN << "Please enter an instruction: " << SStyle::NC;

    }

    Sys_Util::display_sc_msg();
    std::cout << SStyle::YELLOW << "Program terminated..." << SStyle::NC << std::endl;

    return 0;

}
