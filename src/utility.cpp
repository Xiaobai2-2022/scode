#include "utility.hpp"

// check if value is in between the lower and upper bound
bool Utility::is_in_range(unsigned int val_, unsigned int lower_, unsigned int upper_) {

    if(val_ >= lower_ && val_ <= upper_) {
        return true;
    }
    return false;

}
