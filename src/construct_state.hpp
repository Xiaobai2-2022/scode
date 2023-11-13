#ifndef _CTOR_STATE_HPP_
#define _CTOR_STATE_HPP_

#include <fstream>
#include <sstream>
#include <unordered_map>

#include "error_output.hpp"
#include "generate_code.hpp"
#include "state.hpp"

class Ctor_State;

class Ctor_State {

    public:
        // Generates binary code into state by given the initial state
        static bool sc_bin_to_state(std::string, State &);

};

#endif
