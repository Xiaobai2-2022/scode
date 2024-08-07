#ifndef _APP_UTIL_
#define _APP_UTIL_

#include <filesystem>
#include <sys/ioctl.h>
#include <unistd.h>
#include <unordered_map>

class App_Util;

class App_Util {

    public:
        // Clears the termimal
        static void clear_terminal();
        // Get the terminal size
        static void get_terminal_size(unsigned int &, unsigned int &);

    public:
        // Print SCode message
        static void display_sc_msg(std::ostream &);

    public:
        // Find the file with a specific extension
        static std::unordered_map<std::filesystem::path, int> find_file(const std::filesystem::path& directory, const std::string& extension);

};

#endif
