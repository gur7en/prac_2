#include "date.hpp"
#include "result.hpp"

#include <gtest/gtest.h>

// ============================================================================

Date::Date(int year, int month, int day)
    : year(year), month(month), day(day)
{
}


Date::Date(FILE* in, Result& res)
{
    read(in, res);
}


void Date::read(FILE* in, Result& res)
{
    if(res != Result::Success) {
        return;
    }
    if(3 != fscanf(in, "%d.%d.%d", &year, &month, &day)) {
        res = Result::ErrorReading;
        return;
    }
    if(!check()) {
        res = Result::ErrorDate;
    }
}


int Date::check()
{
    if(year == 0) {
        return 0;
    }
    if(month < 1 || month > 12) {
        return 0;
    }
    int max_day = 31;
    if(month == 2) {
        if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    } else switch(month) {
        case 4: case 6: case 9: case 11:
            max_day = 30;
        default:
            ;
    }
    if(day < 1 || day > max_day) {
        return 0;
    }
    return 1;
}


void Date::print(FILE* out)
{
    fprintf(out, "%i.%02i.%02i", year, month, day);
}


