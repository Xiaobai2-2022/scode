#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <map>
#include <string>

class Utility {

    public:
        // Maps instructions to an integer for switch purpose
        static const std::map<std::string, int> rv_inst;

    public:
        // Check if the the value is in range of the other two values
        static bool is_in_range(unsigned int, unsigned int, unsigned int);
        // Check if the string has the starting substring of the other string
        static bool is_start_with(std::string, std::string);
        
    // public:
    //     // Calculate the nth power of a value
    //     static unsigned int pow(unsigned int, unsigned int);

};

#endif
