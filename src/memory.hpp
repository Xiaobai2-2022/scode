#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include <map>

#include "memory_cell.hpp"
#include "word.hpp"

class Mem_Cell {

    private:
        Cell value;
        Mem_Cell *next;
        Mem_Cell *prev;

    public:
        Mem_Cell(Word);                                 // Constructor, set the value to the word given
        ~Mem_Cell();                                    // Destructor, removes this value from the chain

    public:
        void attach_to_back(Mem_Cell *);
        void attach_to_front(Mem_Cell *);

};

class Memory {

    private:
        Mem_Cell *head;
        Mem_Cell *tail;
        std::map<unsigned long, Mem_Cell*> mem;

    public:
        Memory();                                       // Constructor, constructs a empty memory
        ~Memory();                                      // Destructor, clear the entire memory

    public:
        void add(unsigned long, Word);
        Word remove(unsigned long);

};

#endif
