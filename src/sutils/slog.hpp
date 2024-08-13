#ifndef _SLOG_HPP_
#define _SLOG_HPP_

#include "../senv/s_env_setting.hpp"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "sstyle.hpp"

class SLog;

class SLog {

    private:
        // The name of the log file, has to be set.
        static std::string file_name;

    public:
        // Clean all log files
        static void clean();
        // Set the name of the log file
        static void set_file_name(std::string);
    public:
        // Log a message
        static unsigned int log(std::string);

};

#endif
