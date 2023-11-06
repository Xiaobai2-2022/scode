#include "memory.hpp"

// Constructor, set the value to the word given
Mem_Node::Mem_Node(Cell val_) : value{val_}, next{nullptr}, prev{nullptr} {}

// Destructor, does nothing
Mem_Node::~Mem_Node() {}

// Attach an element to the front of the current
void Mem_Node::attach_to_front(Mem_Node *n_) {
     this->prev = n_;
}

// Attach an element to the back of the current
void Mem_Node::attach_to_back(Mem_Node *n_) {
     this->next = n_;
}

// 
