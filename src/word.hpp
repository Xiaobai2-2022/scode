#ifndef _CODE_HPP_
#define _CODE_HPP_

#include <iostream>
#include <string>

#define ulong unsigned long

class Word;

class Word {

    private:
        unsigned int value;

    public:
        Word();                                         // Default constructor, sets the value to 0
        Word(int);                                      // int constructor, sets converts the input to unsigned int
        Word(unsigned int);                             // unsigned int constructor, sets the value to the input
        Word(std::string);                              // string constructor, sets the value to the input

    public:
        Word(const Word &);                             // Copy constructor, provides deep copy
        Word &operator=(const Word &);                  // Copy Assignment operator, provides deep copy
        Word(Word &&);                                  // Move constructor, provides shallow copy
        Word &operator=(Word &&);                       // Move Assignemnt operator, provides shallow copy
        ~Word();                                        // Deconstructor, do nothing
        
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
        Word operator%(unsigned int);                                               // Modulo operator
        Word operator<<(unsigned int);                                              // Left shift operator
        Word operator>>(unsigned int);                                              // Right shift operator`
        Word &operator+=(const Word &);                                             // Addition equal operator
        Word &operator-=(const Word &);                                             // Subtraction equal operator
        Word &operator%=(unsigned int);                                             // Modulo equal operator
        Word &operator<<=(unsigned int);                                            // Left shift equal operator
        Word &operator>>=(unsigned int);                                            // Right shift equal operator

    public:
        friend std::ostream &operator<<(std::ostream &, const Word &);              // Output operator

    public:
        Word limit(unsigned int, unsigned int);                                     // Limit the word in range of the two unsigned int

};

#endif
