#include "result.hpp"


Result::Result()
    : resultCode(Success), stringInFileNum(0)
{
}


void Result::counterStrNum(FILE* f)
{
    long pos = ftell(f);
    rewind(f);
    stringInFileNum = 0;
    for(long i = 0; i < pos; ++i) {
        int cur = fgetc(f);
        if(cur == '\n') {
            ++stringInFileNum;
        }
    }
}


int Result::getStrNum()
{
    return stringInFileNum;
}


bool Result::operator == (Result::Code code) const
{
    return resultCode == code;
}


bool Result::operator != (Result::Code code) const
{
    return resultCode != code;
}


Result::Code Result::operator = (const Result::Code code)
{
    resultCode = code;
    return resultCode;
}

