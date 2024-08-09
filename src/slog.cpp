#include "slog.hpp"

// Assign default value
std::string SLog::file_name = "_log.slog";

void SLog::clean() {
    std::system("rm *.slog");
}

void SLog::set_file_name(std::string file_name) {
    SLog::file_name = file_name;
    std::cout << SColor::green << "Log created." << SColor::nc << std::endl;
    SLog::log(SLog::file_name + " is successfully created.");
}

unsigned int SLog::log(std::string msg) {

    std::ofstream fout(SLog::file_name, std::ios_base::app);

    if(!fout.is_open()) {
        std::cout << SColor::red << "Fatal, log file failed to open." << SColor::nc << std::endl;
        return -1;
    }

    std::time_t t = std::time(nullptr);
    std::tm* cur_t = std::localtime(&t);

    fout << std::put_time(cur_t, "%Y-%m-%d %H:%M:%S") << " : " << msg << std::endl;

    return 0;

}