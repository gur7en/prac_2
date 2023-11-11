#include <string>

#include "date.hpp"
#include "result.hpp"

#ifndef RATE_H
#define RATE_H

class Rate {
    friend class TestRate;
    public:
        Rate(FILE* in, Result& res);
        void read(FILE* in, Result& res);
        void print(FILE* out);
    private:
        Rate();
        std::string source;
        std::string destin;
        double rate;
        Date date;
        void read_do(FILE* in, std::string& out, Result& res);
};

#endif // RATE_H
