#include <stdio.h>
#include "result.hpp"

#ifndef DATE_H
#define DATE_H

class Date {
    friend class TestDate;
    public:
        Date(int year, int month, int day);
        Date(FILE* in, Result& res);
        void read(FILE* in, Result& res);
        void print(FILE* out);
    private:
        int year;
        int month;
        int day;
        int check();
};

#endif // DATE_H
