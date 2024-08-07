#include "app_interface.hpp"

unsigned int assemble_file();
void init();
int main();

unsigned int assemble_file() {

    App_Util::clear_terminal();
    App_Util::display_sc_msg(std::cout);

    std::filesystem::path cur_directory{std::filesystem::current_path()};

    std::map<int, std::filesystem::path> dir;

    dir = App_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        std::cout << pair.first << ": " << pair.second.filename() << std::endl;
    }

    unsigned int file_id{0};

    if(dir.size() == 0) {
        std::cout << "Internal error SVM-Prod-1-0001, required file does not exist, aborted." << std::endl;
        return 1;
    } else if(dir.size() == 1) {
        std::cout << "Total: 1 entry, proceed to compile..." << std::endl;
    } else {
        std::cout << "Total: " << dir.size() << " entrie(s)." << std::endl;
        std::cout << "Please select the file number you wish to compile..." << std::endl;
        if(std::cin >> file_id) {
            if(file_id <= 0 || file_id > dir.size()) {
                std::cout << "Internal error SVM-Prod-1-0003, selected number is out of range, aborted." << std::endl;
                return 3;
            }
        } else {
            std::cout << "Internal error SVM-Prod-1-0002, input should be an integer, aborted." << std::endl;
            return 2;
        }
    }

    return 0;

}

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    App_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

}

int main() {

    init();
    assemble_file();

}