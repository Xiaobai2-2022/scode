#ifndef _CTOR_STATE_HPP_
#define _CTOR_STATE_HPP_

#include "../senv/s_env_setting.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "generate_code.hpp"

#include "../sdatas/memory_cell.hpp"
#include "../sdatas/state.hpp"

#include "../sutils/color.hpp"
#include "../sutils/error_output.hpp"
#include "../sutils/slog.hpp"
#include "../sutils/utility.hpp"

class Ctor_State;

class Ctor_State {

    public:
        // Generates binary code into state by given the initial state
        static bool sc_bin_to_state(std::string, State &);

};

#endif
