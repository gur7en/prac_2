#include <string>
#include <stdio.h>
#include <stdarg.h>
#include "result.hpp"
#include "file.hpp"

// ============================================================================

FileIO::FileIO(FILE* f, Result& res)
{
    file = f;
    if(!file) {
        res = Result::ErrorOpen;
    }
}


FileIO::FileIO(const char* name, const char* mode, Result& res)
{
    file = fopen(name, mode);
    if(!file) {
        res = Result::ErrorOpen;
    }
}


FileIO::~FileIO()
{
    if(file) {
        fclose(file);
    }
}


void FileIO::getInteger(int& out, Result& res)
{
    int scfr = fscanf(file, "%i", &out);
    checkScanF(1, scfr, res);
}


void FileIO::getDouble(double& out, Result& res)
{
    int scfr = fscanf(file, "%lf", &out);
    checkScanF(1, scfr, res);
}


void FileIO::getChar(char& out, Result& res)
{
    int scfr = fscanf(file, "%c", &out);
    checkScanF(1, scfr, res);
}


void FileIO::getQuotedString(std::string& out, Result& res)
{
    if(res != Result::Success) {
        return;
    }
    for(int i = 0; i <= 1; ++i) {
        for(;;) { 
            int cur = fgetc(file);
            if(cur == '"' || cur == EOF) { // Opening quote
                break;
            }
            if(i) {
                out += (char)cur;
            }
        }
    }
    if(feof(file)) {
        res = Result::EndOfFile;
    }
}

void FileIO::checkScanF(int expect, int real, Result& res)
{
    if(real == expect) {
        ;
    } else if(real == EOF) {
            res = Result::EndOfFile;
    } else {
            res = Result::ErrorReading;
    }
}


int FileIO::getFormat(const char* format, ...)
{
    va_list vl;
    va_start(vl, format);
    int scfr = vfscanf(file, format, vl);
    va_end(vl);
    return scfr;
}


int FileIO::putFormat(const char* format, ...)
{
    va_list vl;
    va_start(vl, format);
    int prfr = vfprintf(file, format, vl);
    va_end(vl);
    return prfr;
}


void FileIO::getStringNumber(size_t& pos)
{
    pos = stringNumber;
}
