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

    std::chrono::_V2::system_clock::time_point now = std::chrono::system_clock::now();

    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* cur_t = std::localtime(&t);

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    fout << std::put_time(cur_t, "%Y-%m-%d %H:%M:%S") << "." << std::setw(3) << std::setfill('0') << ms.count() << " : " << msg << std::endl;

    return 0;

}