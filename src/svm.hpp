#ifndef _SVM_HPP_
#define _SVM_HPP_

#include <string>
#include <vector>

#include "sdatas/state.hpp"

class SVM {

    private:
        State cur;
        std::vector<State> history;

    public:
        // Constructor, takes in the file name for the binary file
        SVM(std::string);

    public:
        // Undo the last step
        bool undo();
        // Update the State
        bool update();

};

#endif
