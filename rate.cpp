#include "rate.hpp"

// ============================================================================

void read_string(FILE* in, std::string& out)
{
    for(;;) { 
        int cur = fgetc(in);
        if(cur == '"') { // Opening quote
            break;
        } else if(cur == EOF) {
            return;
        }
    }
    for(;;) {
        int cur = fgetc(in);
        if(cur == '"' || cur == EOF) { // Ending quote
            return;
        }
        out += (char)cur;
    }
}

