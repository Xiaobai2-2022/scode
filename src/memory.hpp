#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include <map>

#include "memory_cell.hpp"
#include "word.hpp"

class Mem_Node {

    private:
        Cell value;
        Mem_Node *next;
        Mem_Node *prev;

    public:
        Mem_Node(Cell);                                 // Constructor, set the value to the word given
        ~Mem_Node();                                    // Destructor, removes this value from the chain

    public:
        void attach_to_back(Mem_Node *);
        void attach_to_front(Mem_Node *);

};

class Memory {

    private:
        Mem_Node *head;
        Mem_Node *tail;
        std::map<unsigned long, Mem_Node*> mem;

    public:
        Memory();                                       // Constructor, constructs a empty memory
        ~Memory();                                      // Destructor, clear the entire memory

    public:
        void add(unsigned long, Word);
        Word remove(unsigned long);

    public:
        class Bidirectional_Iterator {                              // Bidirectional Iterator for memory

            Mem_Node *cur;
            Bidirectional_Iterator(Mem_Node *);

            public:
                Bidirectional_Iterator &operator++();
                Bidirectional_Iterator &operator--();
                bool operator!=(const Bidirectional_Iterator &);
                Cell &operator*();
                friend Memory;

        };
        Bidirectional_Iterator begin();
        Bidirectional_Iterator end();

};

#endif
