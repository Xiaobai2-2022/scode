#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <cmath>
#include <climits>
#include <string>
#include <unordered_map>

#include "../sdatas/word.hpp"

class Utility;

class Utility {

    public:
        // Maps instructions to an integer for switch purpose
        static const std::unordered_map<std::string, int> inst;

    public:
        // Check if the the value is in range of the other two values
        static bool is_in_range(unsigned int, unsigned int, unsigned int);
        // Check if the string has the starting substring of the other string
        static bool is_start_with(std::string, std::string);
        
    public:
        // Calculate the power of an integer value
        static int pow(int, unsigned int);
        // Convert the number into given length word
        static Word change_length(int, unsigned int);
        // Convert the unsigned number into given length word
        static Word change_length_unsigned(int, unsigned int);

};

#endif
