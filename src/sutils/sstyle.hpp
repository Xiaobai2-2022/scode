#ifndef _SSTYLE_HPP_
#define _SSTYLE_HPP_

#include "../senv/s_env_setting.hpp"

#include <string>

class SStyle {

    public:
        const static std::string NC;            // Default

    public:
        const static std::string BLACK;         // Black
        const static std::string RED;           // Red
        const static std::string GREEN;         // Green
        const static std::string YELLOW;        // Yellow
        const static std::string BLUE;          // Blue
        const static std::string MAGENTA;       // Magenta
        const static std::string CYAN;          // Cyan
        const static std::string WHITE;         // White

    public:
        const static std::string BOLD;          // Bold
        const static std::string FAINT;         // Faint
        const static std::string ITALIC;        // Italic
        const static std::string UNDERLINE;     // Underline

    public:
        const static std::string PREV_LINE;     // Print on the previous line

}; // SColor

#endif
