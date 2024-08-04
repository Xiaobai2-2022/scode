#include "app_interface.hpp"

void display_landpage();
void get_terminal_size(unsigned int &, unsigned int &);
void init();
int main();

void display_landpage() {



}

void get_terminal_width(unsigned int &width, unsigned int &height) {

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    width = win.ws_col;
    height = win.ws_row;

}

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

}

int main() {

    init();

}