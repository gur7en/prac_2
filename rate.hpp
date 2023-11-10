#include <string>

#include "date.hpp"
#include "file.hpp"
#include "result.hpp"

#ifndef RATE_H
#define RATE_H

class Rate {
    public:
        Rate(FILE* in, Result& res);
        void read(FILE* in, Result& res);
        void print(FILE* out);
    private:
        std::string source;
        std::string destin;
        double rate;
        Date date;
        void read_do(FILE* in, std::string& out, Result& res);
};

#endif // RATE_H
