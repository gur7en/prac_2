#include <stdio.h>

#ifndef DATE_H
#define DATE_H

struct date {
    int day;
    int month;
    int year;
};


void read_date(FILE* in, date& out);

#endif // DATE_H
