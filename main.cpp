#include <stdio.h>

#include <string>
#include <list>

#include "date.hpp"
#include "rate.hpp"
#include "result.hpp"

#ifdef TEST
#include <gtest/gtest.h>
#endif

// ============================================================================

void read_list(FILE* in, std::list<Rate*>& out, Result& res);
void print_list(std::list<Rate*>& lst);

// ============================================================================

int main(int argc, char* argv[])
{
#ifdef TEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
    FILE* in_file = fopen("in.txt", "r");
    if(!in_file) {
        printf("in.txt not found!");
        return 1;
    }
    Result res;
    std::list<Rate*> rate_lst;
    read_list(in_file, rate_lst, res);
    fclose(in_file);
    if(res == Result::Success) {
        print_list(rate_lst);
    } else {
        printf("Error in record %i, ", res.getStrNum());
        if(res == Result::ErrorReading) {
            printf("incorrect format.\n");
        } else if(res == Result::ErrorDate) {
            printf("incorrect date.\n");
        } else if(res == Result::EndOfFile) {
            printf("unexpected end of file.\n");
        }
    }
    return 0;
}


void read_list(FILE* in, std::list<Rate*>& out, Result& res)
{
    for(;;) {
        Rate* cur = new Rate(in, res);
        if(res != Result::Success) {
            if(res == Result::EndOfFile) {
                res = Result::Success;
            } else {
                res.setStrNum(out.size() + 1);
            }
            delete cur;
            break;
        }
        out.push_back(cur);
    }
}


void print_list(std::list<Rate*>& lst)
{
    for(Rate* cur : lst) {
        cur->print(stdout);
    }
}

