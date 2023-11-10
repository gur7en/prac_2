#include <string>
#include "result.hpp"


#ifndef FILE_H
#define FILE_H

class InterfaceIO {
    public:
        InterfaceIO() {}
        virtual ~InterfaceIO() {}
        virtual void getQuotedString(std::string& out, Result& res) = 0;
        virtual void getInteger(int& out, Result& res) = 0;
        virtual void getDouble(double& out, Result& res) = 0;
        virtual void getChar(char& out, Result& res) = 0;
        virtual int getFormat(const char* format, ...) = 0;
        virtual int putFormat(const char* format, ...) = 0;
        virtual void getStringNumber(size_t& pos) = 0;
};


class FileIO : public InterfaceIO {
    public:
        FileIO(FILE* f, Result& res);
        FileIO(const char* name, const char* mode, Result& res);
        virtual ~FileIO();
        void getWord(std::string& out, Result& res);
        void getQuotedString(std::string& out, Result& res);
        void getInteger(int& out, Result& res);
        void getDouble(double& out, Result& res);
        void getChar(char& out, Result& res);
        int getFormat(const char* format, ...);
        int putFormat(const char* format, ...);
        void getStringNumber(size_t& pos);
    private:
        FILE* file;
        size_t stringNumber;
        void checkScanF(int expect, int real, Result& res);
};

#endif // FILE_H
