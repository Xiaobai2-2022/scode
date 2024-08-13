#ifndef _SVM_HPP_
#define _SVM_HPP_

#include "../senv/s_env_setting.hpp"

#include <chrono>
#include <iomanip>
#include <stack>
#include <string>
#include <thread>

#include "../sdatas/state.hpp"

#include "../smakes/construct_state.hpp"
#include "../smakes/generate_state.hpp"

#include "../sutils/slog.hpp"
#include "../sutils/sstyle.hpp"
#include "../sutils/sys_util.hpp"

class SVM {

    private:
        State cur;
        std::stack<State> history;
        unsigned int count;

    private:
        static void countdown_helper();

    public:
        // Constructor, takes in the file name for the binary file
        SVM(std::string);

    public:
        // Print the VM
        void print() const;
        // Update the State
        void update();
        // Undo the last step
        void undo();

};

#endif
