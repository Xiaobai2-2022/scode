#ifndef _SVM_HPP_
#define _SVM_HPP_

#include "../senv/s_env_setting.hpp"

#include <stack>
#include <string>

#include "../sdatas/state.hpp"

#include "../smakes/construct_state.hpp"

#include "../sutils/color.hpp"
#include "../sutils/slog.hpp"

class SVM {

    private:
        State cur;
        std::stack<State> history;
        unsigned int count;

    public:
        // Constructor, takes in the file name for the binary file
        SVM(std::string);

    public:
        // Update the State
        bool update();
        // Undo the last step
        bool undo();

};

#endif
