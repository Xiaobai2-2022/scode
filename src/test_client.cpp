#include "test_interface.hpp"

void run_word_test();
void run_generate_code_test();
void run_utility_test();
void run_ctor_rv_test();
void run_reg_test();
void run_mem_test();
void run_port_test();
void run_state_test();
void run_ctor_state_test();
void run_state_test(State &);
int main();

// Execute the Word tests
void run_word_test() {

    std::vector<Word> list_words;       // defined list of word for testing
    std::size_t count{0};               // the current count of words
    char type{'\0'};                    // input
    int i_val{};                        // int value
    unsigned int u_i_val{};             // unsigned int value
    std::string s_val{};                // string value

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * E - Create a default constructor test for Word, then print out the result
     * I - Create a signed int test for Word, then print out the result
     * S - Create a string test for Word, then print out the result
     * U - Create an unsigned int test for Word, then print out the result
     */
    switch (type) {
    case 'e': case 'E':
        // construct, print, add to count
        list_words.emplace_back(Word{});
        std::cout << "Word #" << count << " is: " << list_words.at(count) << std::endl;
        count++;
        break;

    case 'i': case 'I':
        // read user input for an signed int
        std::cin >> i_val;
        // construct, print, add to count
        list_words.emplace_back(Word{i_val});
        std::cout << "Word #" << count << " is: " << list_words.at(count) << std::endl;
        count++;
        break;

    case 's': case 'S':
        // read user input for a formated string
        std::cin >> s_val;
        // construct, print, add to count
        list_words.emplace_back(Word{s_val});
        std::cout << "Word #" << count << " is: " << list_words.at(count) << std::endl;
        count++;
        break;

    case 'u': case 'U':
        // read user input for an unsigned int
        std::cin >> u_i_val;
        // construct, print, add to count
        list_words.emplace_back(Word{u_i_val});
        std::cout << "Word #" << count << " is: " << list_words.at(count) << std::endl;
        count++;
        break;
    
    default:
        break;
    }

}

// Execute the Generate Code tests
void run_generate_code_test() {

    std::vector<Word> list_words;       // defined list of word for testing
    std::pair<Word, int> cur_gen_out;   // the currect generate output
    std::size_t count{0};               // the current count of words
    char type{'\0'};                    // input
    unsigned int rd;                    // rd
    unsigned int rs1;                   // rs1
    unsigned int rs2;                   // rs2

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * R - Run R-type Instructions
     *     + - Run add Instruction
     *     = - Run beq Instruction
     */
    switch (type) {
    case 'r': case 'R':

        std::cin >> type;
            
        switch (type) {
        case '+':
            // Read input registers
            std::cin >> rd >> rs1 >> rs2;
            cur_gen_out = Gen_Code::ADD(rd, rs1, rs2);
            list_words.emplace_back(cur_gen_out.first);
            // Check if command is valid
            if(cur_gen_out.second == 0) {
                std::cout << "Word generated by add command is: " << list_words.at(count) << std::endl;
            } else {
                std::cout << "An error occured in generating add command, invalid register input." << std::endl;
            }
            count++;
            break;

        // case '=':
        //     // Read input registers
        //     std::cin >> rs1 >> rs2;
        //     cur_gen_out = Gen_Code::add(rd, rs1, rs2);
        //     list_words.emplace_back(cur_gen_out.first);
        //     // Check if command is valid
        //     if(cur_gen_out.second == 0) {
        //         std::cout << "Word generated by add command is: " << list_words.at(count) << std::endl;
        //     } else {
        //         std::cout << "An error occured in generating add command, invalid register input." << std::endl;
        //     }
        //     count++;
        //     break;
            
        default:
            break;
        }

        break;
    
    default:
            break;
    }

}

void run_utility_test() {

    char type{'\0'};                    // input
    std::string s1;                     // temp string 1
    std::string s2;                     // temp string 2
    int val;                            // temp value
    int len;                            // temp length

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * B - bool typed tests
     *     S - is_start_with
     *     
     * C - calculation typed tests
     *     L - change_length
     */
    switch (type) {
    case 'b': case 'B':

        std::cin >> type;
        
        switch (type) {
        case 's': case 'S':
            // Read strings
            std::cin >> s1 >> s2;
            std::cout << (Utility::is_start_with(s1, s2) ? "true" : "false") << std::endl;
            break;
    
        default:
            break;
        }

        break;
    
    case 'c': case 'C':

        std::cin >> type;

        switch (type) {
        case 'l': case 'L':
            // Read input
            std::cin >> val >> len;
            std::cout << "Imm value is: " << Utility::change_length(val, len) << "." << std::endl;
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
    
}

void run_ctor_rv_test() {

    char type{'\0'};                    // input
    std::string s_if;                   // string for input file
    std::string s_of;                   // string for output file

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * 0 - 1 to 0 tests
     * B - 0 to bin tests
     *     
     */
    switch (type) {
    case 'b': case 'B':
        // Read file names
        std::cin >> s_if >> s_of;
        // Check if the operation is completed correctly
        if(Ctor_RV::rv_assembly0_to_bin(s_if, s_of)) {
            // Print the entire out file
            std::ifstream fin(s_of);
            std::string cur_line;
            while(std::getline(fin, cur_line)) {
                std::cout << cur_line << std::endl;
            }
        }
        std::cout << std::endl;
        break;
    
    case '0':
        // Read file names
        std::cin >> s_if >> s_of;
        // Check if the operation is completed correctly
        if(Ctor_RV::rv_assembly1_to_assembly0(s_if, s_of)) {
            // Print the entire out file
            std::ifstream fin(s_of);
            std::string cur_line;
            while(std::getline(fin, cur_line)) {
                std::cout << cur_line << std::endl;
            }
        }
        std::cout << std::endl;
        break;
    
    default:
        break;
    }

}

void run_reg_test() {

    char type{'\0'};                    // input
    unsigned long index;                // index of the reg
    int val;                            // value to be update

    Reg r{};

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * P - print the reg
     * Q - quit
     * R - read the reg
     * W - write to the reg
     *     
     */
    while(type != 'q') {

        switch (type) {
        case 'p': case 'P':
            std::cout << r << std::endl;
            break;
        case 'r': case 'R':
            std::cin >> index;
            std::cout << r.read_cell(index) << std::endl;
            break;
        case 'w': case 'W':
            std::cin >> index >> val;
            std::cout << r.write_cell(Cell{1, index, Word{val}}) << std::endl;
        case 'q': case 'Q': default:
            type = 'q';
            break;
        }

        std::cin >> type;

    }

}

void run_mem_test() {

    char type{'\0'};                    // input
    unsigned long index;                // index of the memory
    int val;                            // value
    Cell temp;                          // temporary cell

    std::cin >> type;

    Memory m{};

    /**
     * Test Methods (Not case sensitive)
     * 
     * A - add an id and value to memory
     * C - clears the memory
     * I - insert an id and value to memory from back
     * P - print the mem
     * R - remove an id from memory
     *     
     */
    while(type != 'q') {

        switch (type) {
        case 'a': case 'A':
            std::cin >> index >> val;
            temp = Cell{0, index, Word{val}};
            m.add(temp);
            break;
        case 'c': case 'C':
            m.clear();
            break;
        case 'i': case 'I':
            std::cin >> index >> val;
            temp = Cell{0, index, Word{val}};
            m.add_to_back(temp);
            break;
        case 'p': case 'P':
            for(auto it{m.begin()}; it != m.end(); ++it) {
                std::cout << (*it);
            }
            std::cout << std::endl;
            break;
        case 'r': case 'R':
            std::cin >> index;
            m.remove(index);
            break;
        case 'q': case 'Q': default:
            type = 'q';
            break;
        }

        std::cin >> type;

    }

}

void run_port_test() {

    char type{'\0'};                    // input
    unsigned long index;                // index of the port
    int val;                            // value to be update

    Port p{};

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * P - print the port
     * Q - quit
     * R - read the port
     * W - write to the port
     *     
     */
    while(type != 'q') {

        switch (type) {
        case 'p': case 'P':
            std::cout << p << std::endl;
            break;
        case 'r': case 'R':
            std::cin >> index;
            std::cout << p.read_cell(index) << std::endl;
            break;
        case 'w': case 'W':
            std::cin >> index >> val;
            std::cout << p.write_cell(Cell{2, index, Word{val}}) << std::endl;
        case 'q': case 'Q': default:
            type = 'q';
            break;
        }

        std::cin >> type;

    }

}

void run_state_test() {

    char type{'\0'};                    // input
    unsigned int type_id;               // type
    unsigned long index;                // index
    int val;                            // value to be update
    std::string s_val;                  // string value

    State s{};

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * C - resets the state
     * F - force into the state
     * P - print the state
     * Q - quit
     * S - force string into the memory
     * U - update to next state
     *     
     */
    while(type != 'q') {

        switch (type) {
        case 'c': case 'C':
            s.init();
            break;
        case 'f': case 'F':
            std::cin >> type_id >> index >> val;
            s.set_value_in_to_state(Cell{type_id, index, Word{val}});
            break;
        case 'p': case 'P':
            std::cout << s << std::endl;
            break;
        case 's': case 'S':
            std::cin >> index >> s_val;
            s.set_value_in_to_state(Cell{MEMORY, index, s_val});
            break;
        case 'u': case 'U':
            std::cout << Gen_State::update_state(s) << std::endl;
            break;
        case 'q': case 'Q': default:
            type = 'q';
            break;
        }

        std::cin >> type;

    }

}

void run_ctor_state_test() {

    char type{'\0'};                    // input
    std::string s_if;                   // string for input file
    State init_state{};                 // inital state

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * C - construct state from file and print
     * P - run C and pass the state to run_state_test
     *     
     */
    switch (type) {
    case 'c': case 'C':
        // Read file names
        std::cin >> s_if;
        // Check if the operation is completed correctly
        if(Ctor_State::sc_bin_to_state(s_if, init_state)) {
            std::cout << init_state << std::endl;
        }
        break;
    case 'p': case 'P':
        // Read file names
        std::cin >> s_if;
        // Check if the operation is completed correctly
        if(Ctor_State::sc_bin_to_state(s_if, init_state)) {
            std::cout << init_state << std::endl;
        }
        // Pass the state into void run_state_test(State &)
        run_state_test(init_state);
    
    default:
        break;
    }

}

void run_state_test(State &state) {

    char type{'\0'};                    // input

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * P - print the state
     * Q - quit
     * U - update to next state
     *     
     */
    while(type != 'q') {

        switch (type) {
        case 'p': case 'P':
            std::cout << state << std::endl;
            break;
        case 'u': case 'U':
            std::cout << Gen_State::update_state(state) << std::endl;
            break;
        case 'q': case 'Q': default:
            type = 'q';
            break;
        }

        std::cin >> type;

    }

}

int main() {

    char in;

    /**
     * Test Methods (Not case sensitive)
     * 
     * B - Construct State tests
     * C - Construct Risc V Codes
     * G - Generate Code tests
     * M - Memory tests
     * P - Port tests
     * R - Register tests
     * S - State tests
     * Q - Quit
     * U - Utility tests
     * W - Word tests
     */
    while(std::cin >> in) {

        switch (in) {

        case 'b': case 'B':
            run_ctor_state_test();
            break;

        case 'c': case 'C':
            run_ctor_rv_test();
            break;

        case 'g': case 'G':
            run_generate_code_test();
            break;

        case 'm': case 'M':
            run_mem_test();
            break;

        case 'r': case 'R':
            run_reg_test();
            break;
        
        case 's': case 'S':
            run_state_test();
            break;

        case 'p': case 'P':
            run_port_test();
            break;

        case 'q': case 'Q':
            return 0;

        case 'u': case 'U':
            run_utility_test();
            break;
            
        case 'w': case 'W':
            run_word_test();
            break;
        
        default:
            break;
        }

    }

    return 0;

}
