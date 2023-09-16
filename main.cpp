#include <stdio.h>

#include <string>
#include <list>

#include "date.hpp"
#include "rate.hpp"

// ============================================================================

void read_list(FILE* in, std::list<rate*>& out);
void print_list(std::list<rate*>& lst);

// ============================================================================

int main()
{
    FILE* in_file = fopen("in.txt", "r");
    if(!in_file) {
        printf("in.txt not found!");
        return 1;
    }
    std::list<rate*> rate_lst;
    read_list(in_file, rate_lst);
    fclose(in_file);
    print_list(rate_lst);
    return 0;
}


void read_list(FILE* in, std::list<rate*>& out)
{
    for(;;) {
        rate* cur = (rate*)malloc(sizeof(rate));
        read_string(in, cur->source);
        read_string(in, cur->destin);
        fscanf(in, "%lf", &cur->exch_rate);
        read_date(in, cur->exch_date);
        if(feof(in)) {
            free(cur);
            break;
        }
        out.push_back(cur);
    }
}


void print_list(std::list<rate*>& lst)
{
    for(rate* cur : lst) {
        date* cur_date = &cur->exch_date;
        printf("%i.%02i.%02i: ", cur_date->year, 
                cur_date->month, cur_date->day);
        printf("%s/%s = %g\n", cur->source.c_str(), 
                cur->destin.c_str(), cur->exch_rate);
    }
}

