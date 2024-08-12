#ifndef _CTOR_RISC_V_HPP_
#define _CTOR_RISC_V_HPP_

#include "../senv/s_env_setting.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

#include "generate_code.hpp"

#include "../sutils/color.hpp"
#include "../sutils/error_output.hpp"
#include "../sutils/utility.hpp"

class Ctor_RV;

class Ctor_RV {

    public:
        // Assembles Risc-V assembly command 0 to binary code by reading file and output
        static bool rv_assembly0_to_bin(std::string, std::string);
        // Constructs Risc-V assembly command 1 to assembly command 0 by reading file and output
        static bool rv_assembly1_to_assembly0(std::string, std::string);

};

#endif
