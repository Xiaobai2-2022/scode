#include "construct_state.hpp"

bool Ctor_State::sc_bin_to_state(std::string if_name_, State &initial_state_) {

    initial_state_ = State{};

    // Address of the instruction
    ulong address{0};

    // Attempt to open input and output file
    std::ifstream fin(if_name_);
    
    // Check if the input file failed to open
    if(!fin.is_open()) {
        std::cout << "Error constructing rv binary to state." << std::endl;
        std::cout << "Error opening the input file: " << if_name_ << "." << std::endl;
        return false;
    }

    std::string cur_line;
    std::getline(fin, cur_line);

    // Check if the risc-v assembly file is of the correct type
    if(!Utility::is_start_with(cur_line, "SCode Binary")) {
        std::cout << "Error constructing rv binary to state." << std::endl;
        std::cout << "Input file has the wrong type: " << if_name_ << "." << std::endl;
        return false;
    }

    // Access all element of the file
    while(std::getline(fin, cur_line)) {

        std::string word{""};
        std::string temp;

        // Construct the string stream to access all elements on the line
        std::stringstream ssline{cur_line};

        // Read all elements in the string
        while(ssline >> temp) {
            word += temp;
        }

        if(word.length() > 32) {
            return false;
        }

        initial_state_.set_value_in_to_state(Cell{MEMORY, address, Word{word}});

        address += 4;

    }

    return true;

}