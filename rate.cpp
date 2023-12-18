#include <stdio.h>

#include "rate.hpp"
#include "result.hpp"

// ============================================================================

Rate::Rate()
    : rate(0), date(0, 0, 0) // have not gotten to this field yet
{
}


Rate::Rate(FILE* in, Result& res)
    : date(0, 0, 0) // have not gotten to this field yet
{
    read(in, res);
}


void Rate::read(FILE* in, Result& res)
{
    if(res != Result::Success) {
        return;
    }
    source.clear();
    destin.clear();
    read_do(in, source, res);
    read_do(in, destin, res);
    if(res != Result::Success) {
        return;
    }
    if(1 != fscanf(in, "%lf", &rate)) {
        res = Result::ErrorReading;
        return;
    }
    date.read(in, res);
}


void Rate::read_do(FILE* in, std::string& out, Result& res)
{
    if(res != Result::Success) {
        return;
    }
    for(int i = 0; i <= 1; ++i) {
        for(;;) { 
            int cur = fgetc(in);
            if(cur == '"' || cur == EOF) { // Opening quote
                break;
            }
            if(i) {
                out += (char)cur;
            }
        }
    }
    if(feof(in)) {
        res = Result::EndOfFile;
    }
}


void Rate::print(FILE* out)
{
    date.print(out);
    fprintf(out, ": %s/%s = %g\n", source.c_str(), destin.c_str(), rate);
}
