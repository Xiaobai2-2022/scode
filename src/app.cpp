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
    Sys_Util::display_sc_msg(std::cout);

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

    s.update();
    s.update();

    return 0;

}
