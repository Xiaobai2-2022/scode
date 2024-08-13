#include "sys_util.hpp"

void Sys_Util::clear_terminal() {
    std::system("clear");
}

void Sys_Util::clean_repo() {
    std::system("rm *.scg");
}

void Sys_Util::get_terminal_size(unsigned int &width, unsigned int &height) {

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    width = win.ws_col;
    height = win.ws_row;

}

void Sys_Util::flush_cin() {
    // Clear the input buffer to ignore leftover newline characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Sys_Util::display_help_msg() {

    Sys_Util::clear_terminal();
    Sys_Util::display_sc_msg();

    std::cout << SStyle::YELLOW << "Instruction List: " << std::endl
        << "state modification" << std::endl
        << "    update    Update the state by the instruction which address in PC" << std::endl
        << "    undo      Undo the last instruction" << std::endl
        << std::endl
        << "miscellaneous" << std::endl
        << "    help      See the help page" << std::endl
        << "    quit      Terminates the program" << std::endl
        << std::endl;

    std::cout << SStyle::GREEN << "Press enter to continue...";

}

void Sys_Util::display_sc_msg() {
    std::cout << SStyle::BOLD << SStyle::UNDERLINE << SStyle::GREEN << "SCode 2024, Fangxia Technology Ltd." << SStyle::NC << std::endl;
}

std::map<int, std::filesystem::path> Sys_Util::find_file(const std::filesystem::path& directory, const std::string& extension) {

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

unsigned int Sys_Util::conversion(std::string if_name, std::string of_name) {

    std::ifstream fin{if_name};         // The input file
    std::string cur_line;               // The line to read the file
    unsigned int total_steps{1};        // The total number of operation steps
    unsigned int cur_steps{1};          // The current operation step

    // Read the first line(identifier)
    if(!fin.is_open()) {
        std::cout << SStyle::RED << "Internal error SVM-Prod-1-0005." << SStyle::NC << std::endl;
        SLog::log("Internal error SVM-Prod-1-0005, required file \"" + if_name + "\" can not open, aborted.");
    }
    if(!std::getline(fin, cur_line)) {
        std::cout << SStyle::RED << "Internal error SVM-Prod-1-0006." << SStyle::NC << std::endl;
        SLog::log("Internal error SVM-Prod-1-0006, required file \"" + if_name + "\" is empty, aborted.");
    }

    // Check if the type of file is sca1 or sca0
    if(Utility::is_start_with(cur_line, "SCode Assembly 1")) {

        total_steps += 1;
        
        std::string temp_of_name{"temp_sca1_sc0.scg"};
    
        if(Ctor_RV::rv_assembly1_to_assembly0(if_name, temp_of_name)) {

            std::cout << SStyle::GREEN << "Step " << cur_steps << "/" << total_steps << " successful. Proceeding..." << SStyle::NC << std::endl;
            SLog::log("Converted from RV Assembly 1 to RV Assembly 0.");

            cur_steps++;
            if_name = temp_of_name;

            // Open the new file
            fin.close();
            fin.open(if_name);
            
            // Reread the first line(identifier)
            if(!fin.is_open()) {
                std::cout << SStyle::RED << "Internal error SVM-Prod-1-0005." << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0005, required file \"" + if_name + "\" can not open, aborted.");
            }
            if(!std::getline(fin, cur_line)) {
                std::cout << SStyle::RED << "Internal error SVM-Prod-1-0006." << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0006, required file \"" + if_name + "\" is empty, aborted.");
            }

        } else {
            std::cout << SStyle::RED << "Internal error SVM-Prod-1-0004." << SStyle::NC << std::endl;
            SLog::log("Internal error SVM-Prod-1-0004, failed to convert from RV Assembly 1 to RV Assembly 0, aborted.");
            SLog::log("Please see \"" + temp_of_name + "\" for more information...");
            return 4;
        }

    }

    if(Utility::is_start_with(cur_line, "SCode Assembly 0")) {
    
        if(Ctor_RV::rv_assembly0_to_bin(if_name, of_name)) {
            std::cout << SStyle::GREEN << "Step " << cur_steps << "/" << total_steps << " successful. Proceeding..." << SStyle::NC << std::endl;
            SLog::log("Assembled from RV Assembly 0 to RV Binary.");
            return 0;
        } else {
            std::cout << SStyle::RED << "Internal error SVM-Prod-1-0007." << SStyle::NC << std::endl;
            SLog::log("Internal error SVM-Prod-1-0007, failed to convert from RV Assembly 0 to RV Binary, aborted.");
            SLog::log("Please see \"" + of_name + "\" for more information...");
            return 4;
        }

    }
    
    std::cout << SStyle::RED << "Internal error SVM-Prod-1-0008." << SStyle::NC << std::endl;
    SLog::log("Internal error SVM-Prod-1-0008, file format not recognized as any of the SCode assembly products, aborted.");

    return 0;

}

unsigned int Sys_Util::assemble_file(std::string of_name) {

    std::filesystem::path cur_directory{std::filesystem::current_path()};

    std::map<int, std::filesystem::path> dir;

    dir = Sys_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        std::cout << pair.first << ": " << pair.second.filename() << std::endl;
    }

    // Set the ID of the file to the correct one
    unsigned int file_id{1};

    // Check if there are valid files, if there is one, select that one, if multiple, prompt user to select one, if none, returns error
    if(dir.size() == 0) {
        std::cout << SStyle::RED << "Internal error SVM-Prod-1-0001." << SStyle::NC << std::endl;
        SLog::log("Internal error SVM-Prod-1-0001, required file does not exist, aborted.");
        return 1;
    } else if(dir.size() == 1) {
    } else {
        std::cout << "Total: " << dir.size() << " entrie(s)." << std::endl;
        std::cout << SStyle::YELLOW << "Please select the file number you wish to assemble: " << SStyle::NC;
        if(std::cin >> file_id) {
            if(file_id <= 0 || file_id > dir.size()) {
                std::cout << SStyle::RED << "Internal error SVM-Prod-1-0003." << SStyle::NC << std::endl;
                SLog::log("Internal error SVM-Prod-1-0003, selected number is out of range, aborted.");
                return 3;
            }
        } else {
            std::cout << SStyle::RED << "Internal error SVM-Prod-1-0002." << SStyle::NC << std::endl;
            SLog::log("Internal error SVM-Prod-1-0002, input should be an integer, aborted.");
            return 2;
        }

        std::cout << SStyle::GREEN << "Successful, proceed to assemble..." << SStyle::NC << std::endl;
        SLog::log("Assembling file \"" + dir.at(file_id).filename().string() + "\" to RV Binary.");
    }

    std::string if_name{dir.at(file_id)};

    // Send to assemble
    return Sys_Util::conversion(if_name, of_name);

}
