#include "date.hpp"
#include <gtest/gtest.h>

class TestDate : public testing::Test
{
    protected:
        Date date = Date(1, 1, 1); // It's a valid date
        void setYear(int y) { date.year = y; }
        void setMonth(int m) { date.month = m; }
        void setDay(int d) { date.day = d; }
        void setDate(int y, int m, int d)
        {
            date.year = y;
            date.month = m;
            date.day = d;
        }
        int runCheck() { return date.check(); }
};


TEST_F(TestDate, YearValid)
{
    setYear(0);
    EXPECT_FALSE(runCheck());
    setYear(1);
    EXPECT_TRUE(runCheck());
    setYear(-1);
    EXPECT_TRUE(runCheck());
    setYear(100000);
    EXPECT_TRUE(runCheck());
    setYear(-100000);
    EXPECT_TRUE(runCheck());
}


TEST_F(TestDate, MonthValid)
{
    setMonth(0);
    EXPECT_FALSE(runCheck());
    setMonth(-1);
    EXPECT_FALSE(runCheck());
    setMonth(13);
    EXPECT_FALSE(runCheck());
    setMonth(-13);
    EXPECT_FALSE(runCheck());
    for(int m = 1; m <= 12; ++m) {
        setMonth(m);
        EXPECT_TRUE(runCheck());
    }
}


TEST_F(TestDate, DayValid)
{
    setMonth(12);
    setDay(0);
    EXPECT_FALSE(runCheck());
    setDay(1);
    EXPECT_TRUE(runCheck());
    setDay(31);
    EXPECT_TRUE(runCheck());
    setDay(32);
    EXPECT_FALSE(runCheck());
    setDay(-1);
    EXPECT_FALSE(runCheck());
    setMonth(11);
    setDay(31);
    EXPECT_FALSE(runCheck());
    setDay(30);
    EXPECT_TRUE(runCheck());
}


TEST_F(TestDate, February)
{
    setMonth(2);
    setDay(29);
    setYear(2000);
    EXPECT_TRUE(runCheck());
    setYear(2020);
    EXPECT_TRUE(runCheck());
    setYear(2021);
    EXPECT_FALSE(runCheck());
    setYear(2100);
    EXPECT_FALSE(runCheck());
}
