#ifndef _ERR_O_HPP_
#define _ERR_O_HPP_

#include "../senv/s_env_setting.hpp"

#include <iostream>

#include "sstyle.hpp"

class Error_Out;

class Error_Out {

    public:
        // Outputs error message
        static void out_error(int, int, std::string);

};

#endif
