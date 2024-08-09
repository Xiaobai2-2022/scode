#include "app_interface.hpp"

unsigned int conversion(std::string, std::string);
unsigned int assemble_file(std::string);
void init();
int main();

unsigned int conversion(std::string if_name, std::string of_name) {

    std::ifstream fin{if_name};     // The input file
    std::string cur_line;           // The line to read the file
    unsigned int total_steps{1};       // The total number of operation steps
    unsigned int cur_steps{1};         // The current operation step

    // Read the first line(identifier)
    if(!fin.is_open()) {
        std::cout << SColor::red << "Internal error SVM-Prod-1-0005." << SColor::nc << std::endl;
        SLog::log("Internal error SVM-Prod-1-0005, required file \"" + if_name + "\" can not open, aborted.");
    }
    if(!std::getline(fin, cur_line)) {
        std::cout << SColor::red << "Internal error SVM-Prod-1-0006." << SColor::nc << std::endl;
        SLog::log("Internal error SVM-Prod-1-0006, required file \"" + if_name + "\" is empty, aborted.");
    }

    // Check if the type of file is sca1 or sca0
    if(Utility::is_start_with(cur_line, "SCode Assembly 1")) {

        total_steps = 2;
        
        std::string temp_of_name{"temp_sca1_sc0.scg"};
    
        if(Ctor_RV::rv_assembly1_to_assembly0(if_name, temp_of_name)) {

            std::cout << SColor::green << "Step " << cur_steps << "/" << total_steps << " successful. Proceeding..." << SColor::nc << std::endl;
            SLog::log("Converted from RV Assembly 1 to RV Assembly 0.");

            cur_steps++;
            if_name = temp_of_name;

            // Open the new file
            fin.close();
            fin.open(if_name);
            
            // Reread the first line(identifier)
            if(!fin.is_open()) {
                std::cout << SColor::red << "Internal error SVM-Prod-1-0005." << SColor::nc << std::endl;
                SLog::log("Internal error SVM-Prod-1-0005, required file \"" + if_name + "\" can not open, aborted.");
            }
            if(!std::getline(fin, cur_line)) {
                std::cout << SColor::red << "Internal error SVM-Prod-1-0006." << SColor::nc << std::endl;
                SLog::log("Internal error SVM-Prod-1-0006, required file \"" + if_name + "\" is empty, aborted.");
            }

        } else {
            std::cout << SColor::red << "Internal error SVM-Prod-1-0004." << SColor::nc << std::endl;
            SLog::log("Internal error SVM-Prod-1-0004, failed to convert from RV Assembly 1 to RV Assembly 0, aborted.");
            SLog::log("Please see \"" + temp_of_name + "\" for more information...");
            return 4;
        }

    }

    
    if(Utility::is_start_with(cur_line, "SCode Assembly 0")) {
    
        if(Ctor_RV::rv_assembly0_to_bin(if_name, of_name)) {
            std::cout << SColor::green << "Step " << cur_steps << "/" << total_steps << " successful. Proceeding..." << SColor::nc << std::endl;
            SLog::log("Converted from RV Assembly 0 to RV Binary.");
            return 0;
        } else {
            std::cout << SColor::red << "Internal error SVM-Prod-1-0007." << SColor::nc << std::endl;
            SLog::log("Internal error SVM-Prod-1-0007, failed to convert from RV Assembly 0 to RV Binary, aborted.");
            SLog::log("Please see \"" + of_name + "\" for more information...");
            return 4;
        }

    }
    
    std::cout << SColor::red << "Internal error SVM-Prod-1-0008." << SColor::nc << std::endl;
    SLog::log("Internal error SVM-Prod-1-0008, file format not recognized as any of the SCode assembly products, aborted.");

    return 0;

}

unsigned int assemble_file(std::string of_name) {

    std::filesystem::path cur_directory{std::filesystem::current_path()};

    std::map<int, std::filesystem::path> dir;

    dir = App_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        std::cout << pair.first << ": " << pair.second.filename() << std::endl;
    }

    // Set the ID of the file to the correct one
    unsigned int file_id{1};

    // Check if there are valid files, if there is one, select that one, if multiple, prompt user to select one, if none, returns error
    if(dir.size() == 0) {
        std::cout << SColor::red << "Internal error SVM-Prod-1-0001." << SColor::nc << std::endl;
        SLog::log("Internal error SVM-Prod-1-0001, required file does not exist, aborted.");
        return 1;
    } else if(dir.size() == 1) {
    } else {
        std::cout << "Total: " << dir.size() << " entrie(s)." << std::endl;
        std::cout << "Please select the file number you wish to compile..." << std::endl;
        if(std::cin >> file_id) {
            if(file_id <= 0 || file_id > dir.size()) {
                std::cout << SColor::red << "Internal error SVM-Prod-1-0003." << SColor::nc << std::endl;
                SLog::log("Internal error SVM-Prod-1-0003, selected number is out of range, aborted.");
                return 3;
            }
        } else {
            std::cout << SColor::red << "Internal error SVM-Prod-1-0002." << SColor::nc << std::endl;
            SLog::log("Internal error SVM-Prod-1-0002, input should be an integer, aborted.");
            return 2;
        }

        std::cout << SColor::green << "Successful, proceed to compile..." << SColor::nc << std::endl;
        SLog::log("Compiling file \"" + dir.at(file_id).filename().string() + "\" to RV Assembly 0.");
    }

    std::string if_name{dir.at(file_id)};

    return conversion(if_name, of_name);

}

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    App_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

    // Clean up the environment
    App_Util::clean_repo();
    App_Util::clear_terminal();
    SLog::clean();

    // Displays message
    App_Util::display_sc_msg(std::cout);

    // Sets the log file name
    SLog::set_file_name("svm_prod_1.slog");

}

int main() {

    // Set the environment to initial state
    init();

    // The name of the binary file generated
    std::string bin_name{"sca_bin.scg"};

    // Try to assemble the file
    if(assemble_file(bin_name) != 0) {
        return -1;
    }

    return 0;

}
