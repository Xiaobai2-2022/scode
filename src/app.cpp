#include "app_interface.hpp"

void assemble_file();
void get_terminal_size(unsigned int &, unsigned int &);
void init();
int main();

void assemble_file() {

    App_Util::clear_terminal();
    App_Util::display_sc_msg(std::cout);

    std::filesystem::path cur_directory{std::filesystem::current_path()};

    std::unordered_map<std::filesystem::path, int> dir;

    dir = App_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        std::cout << (pair.second + 1) << ": " << pair.first.filename() << std::endl;
    }

    std::cout << "Total: " << dir.size() << " entrie(s)." << std::endl;

}

void display_landpage(unsigned int &width) {

    // Currently do nothing

}

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    App_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

    // Display the landpage of the app
    display_landpage(terminal_size.first);

    assemble_file();

}

int main() {

    init();

}