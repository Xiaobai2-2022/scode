#ifndef _CODE_HPP_
#define _CODE_HPP_

#include <iostream>

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

    public:
        friend std::ostream &operator<<(std::ostream &, const Word &);              // Output operator

};

#endif
