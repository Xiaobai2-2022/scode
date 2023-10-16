#include "test_interface.hpp"

void run_word_test();
void run_generate_code_test();
void run_utility_test();
void run_ctor_rv_test();
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
     */
    switch (type) {
    case 'r': case 'R':

        std::cin >> type;
            
        switch (type) {
        case '+':
            // Read input registers
            std::cin >> rd >> rs1 >> rs2;
            list_words.emplace_back(Gen_Code::add(rd, rs1, rs2));
            // Check if command is valid
            if(list_words.at(count) != Word{}) {
                std::cout << "Word generated by add command is: " << list_words.at(count) << std::endl;
            } else {
                std::cout << "An error occured in generating add command, invalid register input." << std::endl;
            }
            count++;
            break;
            
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

    std::cin >> type;

    /**
     * Test Methods (Not case sensitive)
     * 
     * B - bool type tests
     *     s - is_start_with
     *     
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
    
    default:
        break;
    }

}

int main() {

    char in;

    /**
     * Test Methods (Not case sensitive)
     * 
     * C - Construct Risc V Codes
     * G - Generate Code tests
     * Q - Quit
     * U - Utility tests
     * W - Word tests
     */
    while(std::cin >> in) {

        switch (in) {

        case 'c': case 'C':
            run_ctor_rv_test();
            break;

        case 'g': case 'G':
            run_generate_code_test();
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
