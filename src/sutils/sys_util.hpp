#ifndef _SYS_UTIL_
#define _SYS_UTIL_

#include "../senv/s_env_setting.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <map>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include "slog.hpp"
#include "sstyle.hpp"
#include "utility.hpp"

#include "../smakes/construct_risc_v.hpp"

class Sys_Util;

class Sys_Util {

    public:
        // Clears the termimal
        static void clear_terminal();
        // Cleans up repo by removing all the generated files
        static void clean_repo();
        // Create log file
        static void create_log();

    public:
        // Flushes the input
        static void flush_cin();

    public:
        // Get the terminal size
        static void get_terminal_size(unsigned int &, unsigned int &);

    public:
        // Print SCode message
        static void display_sc_msg();

    public:
        // Find the file with a specific extension
        static std::map<int, std::filesystem::path> find_file(const std::filesystem::path& directory, const std::string& extension);

    public:
        // Convert file from RV Assembly to RV Binary (Helper)
        static unsigned int conversion(std::string, std::string);
        // Assemble files to RV Binary
        static unsigned int assemble_file(std::string);

};

#endif
