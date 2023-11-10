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
        void setStrNum(int str_num);
        int getStrNum();
        void setCharInStrNum(int char_num);
        int getCharInStrNum();
        bool operator == (Result::Code);
        bool operator != (Result::Code);
        Code operator = (Result::Code code);
    private:
        Code resultCode;
        int stringInFileNum;
        int charInStringNum;
};

#endif // RESULTS_H
