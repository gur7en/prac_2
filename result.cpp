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


void Result::setCharInStrNum(int char_num)
{
    charInStringNum = char_num;
}


int Result::getCharInStrNum()
{
    return charInStringNum;
}


bool Result::operator == (Result::Code code)
{
    return resultCode == code;
}


bool Result::operator != (Result::Code code)
{
    return resultCode != code;
}


Result::Code Result::operator = (Result::Code code)
{
    return (resultCode = code);
}

