#include "memory.hpp"

// Constructor, set the value to the word given
Mem_Node::Mem_Node(Cell val) : value{val}, next{nullptr}, prev{nullptr} {}

// Destructor, does nothing
Mem_Node::~Mem_Node() {}

// Attach an element to the front of the current
void Mem_Node::attach_to_front(Mem_Node *n) {
     if(!n) {
          this->prev = nullptr;
     }
     this->prev = n;
}

// Attach an element to the back of the current
void Mem_Node::attach_to_back(Mem_Node *n) {
     if(!n) {
          this->next = nullptr;
     }
     this->next = n;
}

// Constructor, create an empty memory
Memory::Memory() : head{nullptr}, tail{nullptr} {}

// Destructor, deletes all nodes
Memory::~Memory() {

     this->clear();

}

Memory::Memory(const Memory &other) : head{nullptr}, tail{nullptr} {

     for(auto lt{other.cbegin()}; lt != other.cend(); ++lt) {
          Cell cpy = lt.cur->value;
          this->add_to_back(cpy);
     }

}

Memory &Memory::operator=(const Memory &other) {

     if(this != &other) {

          this->clear();

          this->head = nullptr;
          this->tail = nullptr;

          for(auto lt{other.cbegin()}; lt != other.cend(); ++lt) {
               Cell cpy = lt.cur->value;
               this->add_to_back(cpy);
          }

     }

     return *this;

}

// Add a cell into memory (in between)
void Memory::add(Cell val) {

     ulong id = val.cell_id();
     Mem_Node *node = new Mem_Node(val);

     // If the list is empty, directly input the node
     if(!this->head) {
          this->head = node;
          this->tail = node;
          this->mem.emplace(std::pair<ulong, Mem_Node *>{id, node});
          return;
     }

     // If id already exists in the memory, delete it; otherwise do nothing
     this->remove(id);

     this->mem.emplace(std::pair<ulong, Mem_Node *>{id, node});

     // Loop through all elements to see where to insert this object
     for(auto it{this->begin()}; it != this->end(); ++it) {
          // Insert if id is lesser
          if(id < (*it).cell_id()) {
               // Check if this is the first element
               if(it == this->begin()) {
                    // Attach new node <=> head, change head to the new node
                    node->attach_to_back(this->head);
                    this->head->attach_to_front(node);
                    this->head = node;
                    return;
               }

               // Attach pre <=> new node <=> cur
               it.cur->prev->attach_to_back(node);
               node->attach_to_front(it.cur->prev);
               node->attach_to_back(it.cur);
               it.cur->attach_to_front(node);
               return;

          }
     }

     // If not found insert at end tail <=> new node
     this->tail->attach_to_back(node);
     node->attach_to_front(this->tail);
     this->tail = node;

}

void Memory::add_to_back(Cell val) {

     ulong id = val.cell_id();
     Mem_Node *node = new Mem_Node(val);

     // If the list is empty, directly input the node
     if(!this->head) {
          this->head = node;
          this->tail = node;
          this->mem.emplace(std::pair<ulong, Mem_Node *>{id, node});
          return;
     }

     // If id already exists in the memory, delete it; otherwise do nothing
     this->remove(id);

     this->mem.emplace(std::pair<ulong, Mem_Node*>{id, node});

     // Loop through all elements to see where to insert this object (reversely)
     for(auto it{this->rbegin()}; it != this->rend(); --it) {
          // Insert if id is greater
          if(id > (*it).cell_id()) {
               // Check if this is the last element
               if(it == this->rbegin()) {
                    // Attach tail <=> new node, change tail to the new node
                    this->tail->attach_to_back(node);
                    node->attach_to_front(this->tail);
                    this->tail = node;
                    return;
               }

               // Attach cur <=> new node <=> next
               node->attach_to_back(it.cur->next);
               it.cur->next->attach_to_front(node);
               it.cur->attach_to_back(node);
               node->attach_to_front(it.cur);
               return;

          }
     }

     // If not found insert in front new node <=> head
     node->attach_to_back(this->head);
     this->head->attach_to_front(node);
     this->head = node;

}

// Remove a cell from memory
void Memory::remove(ulong id) {

     // If id already exists in the memory, delete it; otherwise do nothing
     auto it = this->mem.find(id);
     if(it != this->mem.end()) {

          Mem_Node *cur = it->second;
          Mem_Node *prev = cur->prev;
          Mem_Node *next = cur->next;

          // Attach the previous node and the next node, doing this will detach the currect node
          if(prev) { prev->attach_to_back(next); }
          else { this->head = next; }
          if(next) { next->attach_to_front(prev); }
          else { this-> tail = prev; }

          cur->prev = nullptr;
          cur->next = nullptr;

          // Free the memory for the current node and erase the current node from map
          delete cur;
          cur = nullptr;
          this->mem.erase(id);

     }
     
}

Cell Memory::read(ulong id) {

     // If id does not exists in the memory, return zero cell with the id
     auto it = this->mem.find(id);
     if(it == this->mem.end()) return Cell{MEMORY, id};

     return it->second->value;

}

void Memory::clear() {
     
     // All nodes exists in the map, can be directly deleted
     for(auto it : this->mem) {
          delete it.second;
     }
     this->mem.clear();

     this->head = nullptr;
     this->tail = nullptr;

}

// The iterator constructor
Memory::Bidirectional_Iterator::Bidirectional_Iterator(Mem_Node *cur) : cur{cur} {}

// Equal operator for iterator, returns if the two iterator are the same
bool Memory::Bidirectional_Iterator::operator==(const Bidirectional_Iterator &other) {
     return cur == other.cur;
}

// Not equal operator for iterator, returns if the two iterator are the same
bool Memory::Bidirectional_Iterator::operator!=(const Bidirectional_Iterator &other) {
     return cur != other.cur;
}

// Returns the current containing cell
Cell Memory::Bidirectional_Iterator::operator*() {
     return cur->value;
}

// Goto the next element ++it
Memory::Bidirectional_Iterator &Memory::Bidirectional_Iterator::operator++() {
     this->cur = this->cur->next;
     return *this;
}

// Goto the previous element --it
Memory::Bidirectional_Iterator &Memory::Bidirectional_Iterator::operator--() {
     this->cur = this->cur->prev;
     return *this;
}

// Goto the next element it++
Memory::Bidirectional_Iterator Memory::Bidirectional_Iterator::operator++(int) {
     Bidirectional_Iterator temp = *this;
     ++(*this);
     return temp;
}

// Goto the previous element it--
Memory::Bidirectional_Iterator Memory::Bidirectional_Iterator::operator--(int) {
     Bidirectional_Iterator temp = *this;
     --(*this);
     return temp;
}

// Get the iterator pointing to the first element
Memory::Bidirectional_Iterator Memory::begin() {
     return Bidirectional_Iterator{head};
}

// Get the iterator pointing to the end of list
Memory::Bidirectional_Iterator Memory::end() {
     return Bidirectional_Iterator{nullptr};
}

// Get the iterator pointing to the last element
Memory::Bidirectional_Iterator Memory::rbegin() {
     return Bidirectional_Iterator{tail};
}

// Get the iterator pointing to the end of list in reverse
Memory::Bidirectional_Iterator Memory::rend() {
     return Bidirectional_Iterator{nullptr};
}

// The iterator constructor
Memory::Const_Iterator::Const_Iterator(Mem_Node *cur) : cur{cur} {}

// Not equal operator for iterator, returns if the two iterator are the same
bool Memory::Const_Iterator::operator!=(const Const_Iterator &other) {
     return cur != other.cur;
}

// Returns the current containing cell
Cell Memory::Const_Iterator::operator*() const {
     return cur->value;
}

// Goto the next element ++it
Memory::Const_Iterator &Memory::Const_Iterator::operator++() {
     this->cur = this->cur->next;
     return *this;
}

// Goto the next element it++
Memory::Const_Iterator Memory::Const_Iterator::operator++(int) {
     Const_Iterator temp = *this;
     ++(*this);
     return temp;
}

// Get the constant iterator pointing to the first element
Memory::Const_Iterator Memory::cbegin() const {
     return Const_Iterator{head};
}

// Get the constant iterator pointing to the end of list
Memory::Const_Iterator Memory::cend() const {
     return Const_Iterator{nullptr};
}
