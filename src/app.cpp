#include "app_interface.hpp"

unsigned int assemble_file();
void init();
int main();

unsigned int assemble_file() {

    std::filesystem::path cur_directory{std::filesystem::current_path()};

    std::map<int, std::filesystem::path> dir;

    dir = App_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        std::cout << pair.first << ": " << pair.second.filename() << std::endl;
    }

    // Set the ID of the file to the correct one
    unsigned int file_id{1};

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

    std::string s_if = dir.at(file_id);
    std::string s_of = "svm_prod_1_t_scg_a0.scg";

    if(Ctor_RV::rv_assembly1_to_assembly0(s_if, s_of)) {
        std::cout << SColor::green << "Step 1/2 successful. Proceeding..." << SColor::nc << std::endl;
        SLog::log("Compiled from RV Assembly 1 to RV Assembly 0.");
        SLog::log("Compiling file \"" + dir.at(file_id).filename().string() + "\" to RV Binary.");
    } else {
        std::cout << SColor::red << "Internal error SVM-Prod-1-0004." << SColor::nc << std::endl;
        SLog::log("Internal error SVM-Prod-1-0004, failed to compile from RV Assembly 1 to RV Assembly 0, aborted.");
        SLog::log("Please see \"svm_prod_1_t_scg_a0.scg\" for more information...");
        return 4;
    }

    return 0;

}

void init() {

    // Get the size of the terminal
    std::pair<unsigned int, unsigned int> terminal_size;
    App_Util::get_terminal_size(terminal_size.first, terminal_size.second);

    // std::cout << terminal_size.first << " " << terminal_size.second << std::endl;

    App_Util::clean_repo();
    App_Util::clear_terminal();

    SLog::clean();

    App_Util::display_sc_msg(std::cout);
    SLog::set_file_name("svm_prod_1.slog");

}

int main() {

    init();
    if(assemble_file() != 0) {
        return -1;
    }

    return 0;

}