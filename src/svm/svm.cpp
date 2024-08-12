#include "svm.hpp"

SVM::SVM(std::string if_name) : cur{}, count{} {

    int temp;

    std::cin >> temp;

    if(Ctor_State::sc_bin_to_state(if_name, cur)) {
        this->history.push(cur);
        count++;
        std::cout << SColor::green << "State successfully generated." << SColor::nc << std::endl;
        SLog::log("State Successfully Generated.");
    } else {
        std::cout << SColor::red << "Error while generating state, see log file for more information." << SColor::nc << std::endl;
    }

}
