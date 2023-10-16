#ifndef _CTOR_RISC_V_HPP_
#define _CTOR_RISC_V_HPP_

#include <fstream>
#include <sstream>

#include "generate_code.hpp"    
#include "utility.hpp"

class Ctor_RV {

    public:
        // Constructs Risc-V assembly command to binary code by reading file and output
        static bool rv_assembly0_to_bin(std::string, std::string);

};

#endif
