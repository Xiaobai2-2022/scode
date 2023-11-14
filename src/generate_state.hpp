#ifndef _GEN_STATE_HPP_
#define _GEN_STATE_HPP_

#include "memory_cell.hpp"
#include "state.hpp"
#include "word.hpp"
#include "utility.hpp"

class Gen_State;

class Gen_State {

    // Interperate and update State
    public:
        static int update_state(State &);

    // R Type Instructions
    private:
        static int ADD(unsigned int, unsigned int, unsigned int, State &);

};

#endif
