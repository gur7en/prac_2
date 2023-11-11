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
#else
    if(argc < 2) {
        printf("Usage: \n%s path_to_file\n", argv[0]);
        return 0;
    }
    FILE* in_file = fopen(argv[1], "r");
    if(!in_file) {
        printf("%s is not found!\n", argv[1]);
        return 1;
    }
    Result res;
    std::list<Rate*> rate_lst;
    read_list(in_file, rate_lst, res);
    fclose(in_file);
    if(res == Result::Success) {
        print_list(rate_lst);
    } else {
        printf("Error in line %i, ", res.getStrNum());
        if(res == Result::ErrorReading) {
            printf("incorrect format.\n");
        } else if(res == Result::ErrorDate) {
            printf("incorrect date.\n");
        } else if(res == Result::EndOfFile) {
            printf("unexpected end of file.\n");
        }
    }
    return 0;
#endif
}


void read_list(FILE* in, std::list<Rate*>& out, Result& res)
{
    for(;;) {
        Rate* cur = new Rate(in, res);
        if(res != Result::Success) {
            if(res == Result::EndOfFile) {
                res = Result::Success;
            } else {
                res.counterStrNum(in);
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


