#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include <unordered_map>

#include "memory_cell.hpp"
#include "word.hpp"

class Mem_Node;
class Memory;

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
    
    friend Memory;

};

class Memory {

    private:
        Mem_Node *head;
        Mem_Node *tail;
        std::unordered_map<ulong, Mem_Node*> mem;

    public:
        Memory();                                           // Constructor, constructs a empty memory
        ~Memory();                                          // Destructor, clear the entire memory
        Memory(const Memory &);                             // Copy constructor, copies the memory
        Memory &operator=(const Memory &);                  // Copy assignment operator, copies the memory

    public:
        void add(Cell);                                 // Add from front (for adding in between)
        void add_to_back(Cell);                         // Add to back (for adding code, or stack memory)
        void remove(ulong);
        Cell read(ulong);
        void clear();                                   // Clears the entire memory

    public:
        class Bidirectional_Iterator {                              // Bidirectional Iterator for memory

            Mem_Node *cur;
            explicit Bidirectional_Iterator(Mem_Node *);

            public:
                bool operator==(const Bidirectional_Iterator &);
                bool operator!=(const Bidirectional_Iterator &);
                Cell operator*();
                Bidirectional_Iterator &operator++();
                Bidirectional_Iterator &operator--();
                Bidirectional_Iterator operator++(int);
                Bidirectional_Iterator operator--(int);
                friend Memory;

        };
        Bidirectional_Iterator begin();
        Bidirectional_Iterator end();
        Bidirectional_Iterator rbegin();
        Bidirectional_Iterator rend();

        class Const_Iterator {

            Mem_Node *cur;
            explicit Const_Iterator(Mem_Node *);

            public:
                bool operator!=(const Const_Iterator &);
                Cell operator*() const;
                Const_Iterator &operator++();
                Const_Iterator operator++(int);

                friend Memory;

        };
        Const_Iterator cbegin() const;
        Const_Iterator cend() const;

};

#endif
