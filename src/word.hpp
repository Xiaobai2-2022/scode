#ifndef _CODE_HPP_
#define _CODE_HPP_

#include <iostream>
#include <string>

class Word {

    private:
        unsigned int value;

    public:
        Word();                 // Default constructor, sets the value to 0
        Word(int);              // int constructor, sets converts the input to unsigned int
        Word(unsigned int);     // unsigned int constructor, sets the value to the input
        Word(std::string);      // string constructor, sets the value to the input
        ~Word();                // Deconstructor, do nothing
        
    public:
        bool operator==(const Word &);                                              // Equal comparison operator
        bool operator!=(const Word &);                                              // Not equal comparison operator
        bool operator<(const Word &);                                               // Less than comparison operator
        bool operator>(const Word &);                                               // Greater than comparison operator
        bool operator<=(const Word &);                                              // Less than equal comparison operator
        bool operator>=(const Word &);                                              // Greater than equal comparison operator

    public:    
        Word operator+(const Word &);                                               // Addition operator
        Word operator-(const Word &);                                               // Subtraction operator
        Word operator<<(const Word &);                                              // Left shift operator
        Word operator>>(const Word &);                                              // Right shift operator

    public:
        friend std::ostream &operator<<(std::ostream &, const Word &);              // Output operator

};

#endif
