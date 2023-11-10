#include <stdio.h>
#include "rate.hpp"
#include <gtest/gtest.h>

class TestRate : public testing::Test
{
    protected:
        Rate rate;
        FILE* fmem;
        char* pmem;
        size_t sizemem;
        FILE* fmemout;
        char* pmemout;
        size_t sizememout;
        void SetUp()
        {
            fmem = open_memstream(&pmem, &sizemem);
            fmemout = open_memstream(&pmemout, &sizememout);
        }
        void TearDown()
        {
            if(fmem) {
                fclose(fmem);
                free(pmem);
            }
        }
        void read(Result& res)
        {
            rate.read(fmem, res);
        }
        void read_and_print(Result& res)
        {
            rate.read(fmem, res);
            rate.print(fmemout);
            fflush(fmemout);
        }
};


TEST_F(TestRate, ValidIsValid_1)
{
    Result res;
    const char* exp = "2023.09.02: Доллар США/Российский рубль = 96.34\n";
    fprintf(fmem, "\"%s\" \"%s\" %f %i.%02i.%02i",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 2);
    read_and_print(res);
    EXPECT_EQ(res, Result::Success);
    EXPECT_STREQ(exp, pmemout);
}


TEST_F(TestRate, ValidIsValid_2)
{
    Result res;
    const char* exp = "2023.09.02: Доллар США/Российский рубль = 96.34\n";
    fprintf(fmem, "      \"%s\"      \"%s\"   %f      %i.%02i.%02i    \n  \n",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 2);
    read_and_print(res);
    EXPECT_EQ(res, Result::Success);
    EXPECT_STREQ(exp, pmemout);
}


TEST_F(TestRate, ValidIsValidMultiline_1)
{
    Result res;
    const char* exp = "2023.09.02: Доллар США/Российский рубль = 96.34\n"
        "2023.09.01: Евро/Российский рубль = 104.64\n";

    fprintf(fmem, "\"%s\" \"%s\" %f %i.%02i.%02i\n",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 2);
    read_and_print(res);
    EXPECT_EQ(res, Result::Success);

    fprintf(fmem, "\"%s\" \"%s\" %f %i.%02i.%02i\n",
            "Евро", "Российский рубль", 104.64, 2023, 9, 1);
    read_and_print(res);
    EXPECT_EQ(res, Result::Success);

    EXPECT_STREQ(exp, pmemout);
}


TEST_F(TestRate, ValidIsValidLastLine_1)
{
    Result res;
    const char* exp = "2023.09.02: Доллар США/Российский рубль = 96.34\n";
    fprintf(fmem, "\"%s\" \"%s\" %f %i.%02i.%02i",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 2);
    read_and_print(res);
    EXPECT_EQ(res, Result::Success);
    EXPECT_STREQ(exp, pmemout);
}

TEST_F(TestRate, BrokenDate_1)
{
    Result res;
    fprintf(fmem, "\"%s\" \"%s\" %f %i.%02i.%02i\n",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 32);
    read(res);
    EXPECT_EQ(res, Result::ErrorDate);
}


TEST_F(TestRate, BrokenFormat_1)
{
    Result res;
    fprintf(fmem, "\"%s\" \"%s %f %i.%02i.%02i\n",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 31);
    read(res);
    EXPECT_EQ(res, Result::ErrorReading);
}


TEST_F(TestRate, BrokenFormat_2)
{
    Result res;
    fprintf(fmem, "  %s\" \"%s\" %f %i.%02i.%02i\n",
            "Доллар США", "Российский рубль", 96.34, 2023, 9, 31);
    read(res);
    EXPECT_EQ(res, Result::ErrorReading);
}


