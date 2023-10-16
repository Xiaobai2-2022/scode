#include "word.hpp"

// Default constructor, sets the value to 0
Word::Word() : value{0} {}

// int constructor, sets converts the input to unsigned int
Word::Word(int i_val_) : value{unsigned(i_val_)} {}

// unsigned int constructor, sets the value to the input
Word::Word(unsigned int u_i_val_) : value{u_i_val_} {}

// string constructor, sets the value to the input
Word::Word(std::string s_val_) {

    // set default to 0
    this->value = 0;

    // calculate the length
    std::size_t length{s_val_.length()};

    // check if the length is in range 
    if(length <= 32) {

        
        // loop through the string for '0' (double), '1' (double and add 1), otherwise error and set value to 0
        for(std::size_t i{0}; i < length; i++) {
            char cur{s_val_.at(i)};
            if(cur == '0') {
                this->value *= 2;
            }
            else if(cur == '1') {
                this->value *= 2;
                this->value += 1;
            }
            else {
                this->value = 0;
                std::cout << "Warning, an unrecognized character appears in the input string, value is set to 0 instead." << std::endl;
                break;
            }
        }

    }
    else {
        this->value = 0;
        std::cout << "Warning, string input is too long, value is set to 0 instead." << std::endl;
    }

}

// Deconstructor, do nothing
Word::~Word(){}

// Equal comparison operator
bool Word::operator==(const Word &other) {
    return this->value == other.value;
}

// Not equal comparison operator
bool Word::operator!=(const Word &other) {
    return this->value != other.value;
}

// Less than comparison operator
bool Word::operator<(const Word &other) {
    return this->value < other.value;
}

// Greater than comparison operator
bool Word::operator>(const Word &other) {
    return this->value > other.value;
}

// Less than equal comparison operator
bool Word::operator<=(const Word &other) {
    return this->value <= other.value;
}

// Greater than equal comparison operator
bool Word::operator>=(const Word &other) {
    return this->value >= other.value;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Word &c) {

    unsigned int u_i_val{c.value};
    std::string s_val{""};

    // Convert to string
    for(int i{0}; i < 32; i++) {

        if(u_i_val % 2 == 0) {
            s_val = "0" + s_val;
        } else {
            s_val = "1" + s_val;
        }

        u_i_val /= 2;

        if(i % 4 == 3 && i != 31) {
            s_val = " " + s_val;
        }
        
    }

    os << s_val;
    return os;

}
