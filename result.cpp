#include "result.hpp"


Result::Result()
    : resultCode(Success)
{
}


void Result::setStrNum(int str_num)
{
    stringInFileNum = str_num;
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
    return (resultCode = code);
}

