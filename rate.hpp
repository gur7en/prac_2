#include <string>

#include "date.hpp"

#ifndef RATE_H
#define RATE_H

struct rate {
    std::string source;
    std::string destin;
    double exch_rate;
    date exch_date;
};

void read_string(FILE* in, std::string& out);

#endif // RATE_H
