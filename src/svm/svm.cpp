#include "svm.hpp"

SVM::SVM() : cur{}, count{}, valid{false} {}

SVM::SVM(std::string if_name) : cur{}, count{}, valid{false} {

    if(!Ctor_State::sc_bin_to_state(if_name, cur)) {
        // std::cout << SStyle::RED << "Internal error SVM-Prod-1-0015." << SStyle::NC << std::endl;
        SLog::log("Internal error SVM-Prod-1-0015, an error has occured during state generation, see above.");
        return;
    }
    
    ++this->count;
    std::cout << SStyle::GREEN << "State successfully generated." << SStyle::NC << std::endl;
    SLog::log("State Successfully Generated.");

    SVM::countdown_helper();

    this->print();

    this->valid = true;

}

void SVM::countdown_helper() {

    int seconds{3};
        
    std::cout << std::endl << std::endl;

    while (seconds > 0) {
        std::cout << SStyle::CYAN << SStyle::PREV_LINE << "\rSVM will start in " << std::setw(1) << seconds << " seconds" << std::endl;
        std::cout << std::endl << SStyle::MAGENTA << SStyle::PREV_LINE << "Tip: type help for instruction list." << SStyle::NC;
        std::cout.flush();  // Ensure the updated countdown is printed immediately
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
    }

}

void SVM::clear() {
    Sys_Util::clear_terminal();
    Sys_Util::display_sc_msg();
}

void SVM::display_files() {

    SVM::clear();

    std::filesystem::path cur_directory{std::filesystem::current_path()};
    std::map<int, std::filesystem::path> dir;

    int count{};

    dir = Sys_Util::find_file(cur_directory, ".sca");

    for (const auto &pair : dir) {
        if(count % 2 == 0) std::cout << SStyle::BLUE;
        else std::cout << SStyle::CYAN;
        std::cout << (count + 1) << ": " << pair.second.filename() << std::endl;
        ++count;
    }
    std::cout << SStyle::MAGENTA << "Total: " << dir.size() << " \".sca\" files." << SStyle::NC << std::endl;

    std::cout << std::endl;
    
    dir = Sys_Util::find_file(cur_directory, ".scg");

    for (const auto &pair : dir) {
        if(count % 2 == 0) std::cout << SStyle::BLUE;
        else std::cout << SStyle::CYAN;
        std::cout << (count + 1) << ": " << pair.second.filename() << std::endl;
        ++count;
    }
    std::cout << SStyle::MAGENTA << "Total: " << dir.size() << " \".scg\" files." << SStyle::NC << std::endl;
    
    std::cout << std::endl;

}

bool SVM::is_valid() const {
    return this->valid;
}

void SVM::print() const {

    SVM::clear();

    // Print the PC
    std::cout << SStyle::MAGENTA
        << "PC: ";
    
    if(this->count != 1 && this->cur.get_pc() != this->history.top().get_pc()){
        std::cout << SStyle::BOLD << SStyle::YELLOW;
    } else {
        std::cout << SStyle::CYAN;
    }

    std::cout << "0x" << std::setfill('0') << std::setw(9) << std::hex << this->cur.get_pc()
        << SStyle::NC << std::endl << std::endl;

    // Print the Registers
    std::cout << SStyle::MAGENTA
        << "Registers:"
        << SStyle::NC << std::endl;
    for(ulong i{}; i < Reg::NUM_CELL / 2; ++i) {

        Word cur_val{cur.get_value_in_state(REGISTER, i)};
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Reg(" << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << i << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(REGISTER, i)) {
            std::cout << SStyle::BOLD << SStyle::YELLOW;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(15) << std::dec << cur_val.get_value() << SStyle::NC;
        
        cur_val = cur.get_value_in_state(REGISTER, Reg::NUM_CELL / 2 + i);
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Reg(" << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << (Reg::NUM_CELL / 2 + i) << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(REGISTER, Reg::NUM_CELL / 2 + i)) {
            std::cout << SStyle::BOLD << SStyle::YELLOW;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(10) << std::dec << cur_val.get_value() << SStyle::NC << std::endl;

    }

    std::cout << SStyle::NC << std::endl;
    
    // Print the Ports
    std::cout << SStyle::MAGENTA
        << "Ports:"
        << SStyle::NC << std::endl;
    for(ulong i{}; i < Port::NUM_CELL / 2; ++i) {

        Word cur_val{cur.get_value_in_state(PORT, i)};
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Port(" << "0x" << std::setfill('0') << std::right << std::setw(1) << std::hex << i << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(PORT, i)) {
            std::cout << SStyle::BOLD << SStyle::YELLOW;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(15) << std::dec << cur_val.get_value() << SStyle::NC;
        
        cur_val = cur.get_value_in_state(PORT, Port::NUM_CELL / 2 + i);
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Port(" << "0x" << std::setfill('0') << std::right << std::setw(1) << std::hex << (Port::NUM_CELL / 2 + i) << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(PORT, Port::NUM_CELL / 2 + i)) {
            std::cout << SStyle::BOLD << SStyle::YELLOW;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(10) << std::dec << cur_val.get_value() << SStyle::NC << std::endl;

    }

    std::cout << SStyle::NC << std::right << std::endl;

    // Print the memory
    std::cout << SStyle::MAGENTA
        << "Memory:"
        << SStyle::NC << std::endl;
    Memory m{this->cur.get_mem()};
    for(auto it{m.cbegin()}; it != m.cend(); ++it) {
        if(this->count != 1 && (*it).cell_id() == this->history.top().get_pc()) {
            std::cout << SStyle::YELLOW << SStyle::BOLD;
        } else if((*it).cell_id() % 8 == 0) {
            std::cout << SStyle::BLUE;
        } else {
            std::cout << SStyle::CYAN;
        }
        std::cout << (*it) 
            << " <- 0x" << std::setfill('0') << std::setw(8) << std::hex << (*it).read().get_value()
            << SStyle::NC << std::endl;
    }
    std::cout << std::endl;

}

int SVM::update() {
    
    this->history.push(this->cur);

    Sys_Util::clear_terminal();

    int res{Gen_State::update_state(this->cur)};

    if(!res) {

        SLog::log("State Successfully Updated.");

        ++this->count;

        Sys_Util::clear_terminal();
        this->print();

        return 0;

    }

    if(res == -99) {
        return -99;
    }
    
    std::cout << SStyle::RED << "An error has occured during updating state, aborted." << SStyle::NC << std::endl;
    SLog::log("An error has occured during updating state. Error Code: " + std::to_string(res) + ".");

    return res;

}

bool SVM::undo() {

    if(this->count == 1) return false;
    SLog::log("State Successfully Undid.");

    --this->count;

    this->cur = this->history.top();
    this->history.pop();

    Sys_Util::clear_terminal();
    this->print();

    return true;
    
}

void SVM::display_help_msg() {

    Sys_Util::clear_terminal();
    Sys_Util::display_sc_msg();

    std::cout << SStyle::YELLOW << "Instruction List: " << std::endl
        << "assembling instructions" << std::endl
        << "    display                 Displays the current state" << std::endl
        << "    sc ${if} ${of}          Assemble input file ${if} into output file ${of}, ${of} is optional" << std::endl
        << "state instructions" << std::endl
        << "    create ${f}             Create the state with file ${f}, ${f} is optional" << std::endl
        << "    undo                    Undo the last instruction" << std::endl
        << "    update                  Update the state by the instruction which address in PC" << std::endl
        << std::endl
        << "virtual machine instructions" << std::endl
        << "    clear                   Clears the console screen" << std::endl
        << "    help                    Display the help page" << std::endl
        << "    list                    List .sca/.scg files" << std::endl
        << "    quit                    Terminates the program" << std::endl
        << std::endl;

    std::cout << SStyle::GREEN << "Press enter to continue...";
 
    std::string temp;
    std::getline(std::cin, temp);

}
