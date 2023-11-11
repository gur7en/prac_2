#include <stdio.h>


#ifndef RESULTS_H
#define RESULTS_H

class Result {
    public:
        enum Code {
            Success,
            ErrorOpen,
            ErrorClose,
            EndOfFile,
            ErrorReading,
            ErrorDate
        };
        Result(); 
        void counterStrNum(FILE* f);
        int getStrNum();
        bool operator == (Result::Code code) const;
        bool operator != (Result::Code code) const;
        Code operator = (const Result::Code code);
    private:
        Code resultCode;
        int stringInFileNum;
};

#endif // RESULTS_H
