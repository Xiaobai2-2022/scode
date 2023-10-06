#include "test_interface.hpp"
#include "word.hpp"

int run_word_test();
int main();

// Execute the Word tests
int run_word_test() {

    std::vector<Word> list_words;       // defined list of word for testing
    std::size_t count{0};               // the current count of words
    char type{'\0'};                    // input
    int i_val{};                        // int value
    unsigned int u_i_val{};             // unsigned int value
    std::string s_val{};                // string value

    
    if(std::cin >> type) {

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

        return 0;

    }

    return 1;

}

int main() {

    char in;
    int result{0};

    /**
     * Test Methods (Not case sensitive)
     * 
     * Q - Quit
     * W - Word tests
     */
    while(std::cin >> in) {

        switch (in) {

        case 'q': case 'Q':
            return 0;
            
        case 'w': case 'W':
            result = run_word_test();
            if(result != 0) {
                return result;
            }
            break;
        
        default:
            break;
        }

    }

    return 0;

}
