#include "word.hpp"

// Default constructor, sets the value to 0
Word::Word() : value{0} {}

// int constructor, sets converts the input to unsigned int
Word::Word(int i_val) : value{unsigned(i_val)} {}

// unsigned int constructor, sets the value to the input
Word::Word(unsigned int u_i_val) : value{u_i_val} {}

// string constructor, sets the value to the input
Word::Word(std::string s_val) {

    // set default to 0
    this->value = 0;

    // calculate the length
    std::size_t length{s_val.length()};

    // check if the length is in range 
    if(length <= 32) {

        
        // loop through the string for '0' (double), '1' (double and add 1), otherwise error and set value to 0
        for(std::size_t i{0}; i < length; ++i) {
            char cur{s_val.at(i)};
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

// Copy Constructor, provides deep copy
Word::Word(const Word &other) {
    this->value = other.value;
}

// Copy Assignment operator, provides deep copy
Word &Word::operator=(const Word &other) {
    // self assignment guard
    if(this == &other) return *this;
    this->value = other.value;
    return *this;
}

// Move constructor, provides shallow copy
Word::Word(Word &&other) {
    this->value = other.value;
    other.value = 0;
}

// Move Assignemnt operator, provides shallow copy
Word &Word::operator=(Word &&other) {
    // self assignment guard
    if(this == &other) return *this;
    this->value = other.value;
    other.value = 0;
    return *this;
}

// Deconstructor, do nothing
Word::~Word() {}

// Equal comparison operator
bool Word::operator==(const Word &other) {
    return this->value == other.value;
}

// Equal comparison operator
bool Word::operator==(unsigned int value) {
    return this->value == value;
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

// Addition operator
Word Word::operator+(const Word &other) {
    return Word{this->value + other.value};
}

// Subtraction operator
Word Word::operator-(const Word &other) {
    return Word{this->value - other.value};
}

// Exclusive or operator
Word Word::operator^(const Word &other) {
    return Word{this->value ^ other.value};
}

// Inclusive or operator
Word Word::operator|(const Word &other) {
    return Word{this->value | other.value};
}

// And operator
Word Word::operator&(const Word &other) {
    return Word{this->value & other.value};
}

// Shift left operator
Word Word::operator<<(const Word &other) {
    return Word{this->value << other.value};
}

// Shift right operator
Word Word::operator>>(const Word &other) {
    return Word{this->value >> other.value};
}

// Shift right arithemtic
Word Word::SRA(const Word &other) {
    return Word{static_cast<int>(this->value) >> other.value};
}

// Less than arithmetic
bool Word::LTA(const Word &other) {
    return static_cast<int>(this->value) < static_cast<int>(other.value);
}

// Greater equal arithmetic
bool Word::GEA(const Word &other) {
    return static_cast<int>(this->value) >= static_cast<int>(other.value);
}

// Modulo operator
Word Word::operator%(unsigned int val) {
    return Word{this->value % val};
}

// Left shift operator
Word Word::operator<<(unsigned int val) {
    return Word{this->value << val};
}

// Right shift operator
Word Word::operator>>(unsigned int val) {
    return Word{this->value >> val};
}

// Plus equal operator
Word &Word::operator+=(const Word &other) {
    this->value += other.value;
    return *this;
}

// Minus equal operator
Word &Word::operator-=(const Word &other) {
    this->value -= other.value;
    return *this;
}

// Modulo equal operator
Word &Word::operator%=(unsigned int val) {
    this->value %= val;
    return *this;
}

// Left shift equal operator
Word &Word::operator<<=(unsigned int val) {
    this->value <<= val;
    return *this;
}

// Right shift equal operator
Word &Word::operator>>=(unsigned int val) {
    this->value >>= val;
    return *this;
}

// Returns the value from word
unsigned int Word::get_value() { return this->value; }

// Limit the word in range of the two unsigned int, left is greater than right
Word Word::limit(unsigned int left, unsigned int right) {

    // Calculate the length of the word remaining
    unsigned int length = left - right + 1;
    // Bit shift to clear the left and right side and place at the correct position
    return (((Word{*this} >> right) << (32 - length)) >> (32 - length));

}

// Extend the word to the full range, left is greater than right
Word Word::extend(unsigned int left, unsigned int right) {

    // Calculate the length of the word remaining
    unsigned int length = left - right + 1;
    // Bit shift to clear the left and right side and place at the correct position
    return ((this->limit(left, right) << (32 - length)).SRA(32 - length));

}

// Output operator
std::ostream &operator<<(std::ostream &os, const Word &w) {

    unsigned int u_i_val{w.value};
    std::string s_val{""};

    // Convert to string
    for(int i{0}; i < 32; ++i) {

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
