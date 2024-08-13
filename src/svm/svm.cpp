#include "svm.hpp"

SVM::SVM(std::string if_name) : cur{}, count{} {

    if(!Ctor_State::sc_bin_to_state(if_name, cur)) {
        std::cout << SStyle::RED << "Error while generating state, see log file for more information." << SStyle::NC << std::endl;
        return;
    }
    
    ++this->count;
    std::cout << SStyle::GREEN << "State successfully generated." << SStyle::NC << std::endl;
    SLog::log("State Successfully Generated.");

    SVM::countdown_helper();

    this->print();

}

void SVM::countdown_helper() {

    // int seconds{3};

    // while (seconds > 0) {
    //     std::cout << SStyle::CYAN << "\rSVM will start in " << std::setw(1) << seconds << " seconds";
    //     std::cout << std::endl << SStyle::MAGENTA << "Tip: type help for command list." << SStyle::NC << "\033[F";
    //     std::cout.flush();  // Ensure the updated countdown is printed immediately
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //     --seconds;
    // }

    Sys_Util::clear_terminal();

}

void SVM::print() const {

    // Print the PC
    std::cout << SStyle::MAGENTA
        << "PC: ";
    
    if(this->count != 1 && this->cur.get_pc() != this->history.top().get_pc()){
        std::cout << SStyle::BOLD << SStyle::RED;
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
            std::cout << SStyle::BOLD << SStyle::RED;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(15) << std::dec << cur_val.get_value() << SStyle::NC;
        
        cur_val = cur.get_value_in_state(REGISTER, Reg::NUM_CELL / 2 + i);
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Reg(" << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << (Reg::NUM_CELL / 2 + i) << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(REGISTER, Reg::NUM_CELL / 2 + i)) {
            std::cout << SStyle::BOLD << SStyle::RED;
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
            std::cout << SStyle::BOLD << SStyle::RED;
        }

        std::cout << " <- " << std::setfill(' ') << std::left << std::setw(15) << std::dec << cur_val.get_value() << SStyle::NC;
        
        cur_val = cur.get_value_in_state(PORT, Port::NUM_CELL / 2 + i);
        std::cout << ((i % 2 == 0) ? SStyle::BLUE : SStyle::CYAN)
            << "Port(" << "0x" << std::setfill('0') << std::right << std::setw(1) << std::hex << (Port::NUM_CELL / 2 + i) << "): "
            << cur_val;

        if(this->count != 1 && cur_val != this->history.top().get_value_in_state(PORT, Port::NUM_CELL / 2 + i)) {
            std::cout << SStyle::BOLD << SStyle::RED;
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
        std::cout << (*it) << std::endl;
    }
    std::cout << SStyle::NC << std::endl;

}

void SVM::update() {
    
    this->history.push(this->cur);

    Sys_Util::clear_terminal();

    int res{Gen_State::update_state(this->cur)};

    if(!res) {

        SLog::log("State Successfully Updated.");

        ++this->count;

        Sys_Util::clear_terminal();
        
        this->print();

        return;

    }
    
    SLog::log("An error has occured during updating state.");

}
