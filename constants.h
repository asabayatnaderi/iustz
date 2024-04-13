#pragma once

#include <string>
using namespace std;

namespace color
{
    // Color codes for text output
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string LIGHTGRAY = "\033[37m";
    const string DARKGRAY = "\033[90m";
    const string LIGHTRED = "\033[91m";
    const string LIGHTGREEN = "\033[92m";
    const string LIGHTYELLOW = "\033[93m";
    const string LIGHTBLUE = "\033[94m";
    const string LIGHTMAGENTA = "\033[95m";
    const string LIGHTCYAN = "\033[96m";
}

// Reset text
const string RESET = "\033[0m";
// Bold text
const string BOLD = "\033[1m";
// Underlined text
const string UNDERLINED = "\033[4m";