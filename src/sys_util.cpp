#include "sys_util.hpp"

void App_Util::clear_terminal() {
    std::system("clear");
}

void App_Util::clean_repo() {
    std::system("rm *.scg");
}

void App_Util::get_terminal_size(unsigned int &width, unsigned int &height) {

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    width = win.ws_col;
    height = win.ws_row;

}

void App_Util::display_sc_msg(std::ostream &out) {
    out << "SCode 2024, Fangxia Technology Ltd." << std::endl;
}

std::map<int, std::filesystem::path> App_Util::find_file(const std::filesystem::path& directory, const std::string& extension) {

    std::vector<std::filesystem::path> path{};

    std::map<int, std::filesystem::path> dir{};
    int count{1};

    // Iterate through the file system to find all files with proper extension
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            path.push_back(entry.path());
        }
    }

    // Sort through the file system
    std::sort(path.begin(), path.end());

    for(const auto &p : path) {
        dir.emplace(count++, p);
    }

    return dir;

}
