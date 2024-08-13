#include "svm.hpp"

SVM::SVM(std::string if_name) : cur{}, count{} {

    if(!Ctor_State::sc_bin_to_state(if_name, cur)) {
        std::cout << SColor::red << "Error while generating state, see log file for more information." << SColor::nc << std::endl;
        return;
    }
    
    this->history.push(this->cur);
    ++this->count;
    std::cout << SColor::green << "State successfully generated." << SColor::nc << std::endl;
    SLog::log("State Successfully Generated.");

    SVM::countdown_helper();

    std::cout << this->cur;

}

void SVM::countdown_helper() {

    int seconds{3};

    while (seconds > 0) {
        std::cout << SColor::cyan << "\rSVM will start in " << std::setw(1) << seconds << " seconds";
        std::cout << std::endl << SColor::magenta << "Tip: type help for command list." << SColor::nc << "\033[F";
        std::cout.flush();  // Ensure the updated countdown is printed immediately
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
    }

    Sys_Util::clear_terminal();

}

void SVM::update() {

    Sys_Util::clear_terminal();

    int res{Gen_State::update_state(this->cur)};

    if(!res) {

        SLog::log("State Successfully Updated.");

        this->history.push(this->cur);
        ++this->count;

        Sys_Util::clear_terminal();
        std::cout << this->cur;

        return;

    }
    
    SLog::log("An error has occured during update.");

}
