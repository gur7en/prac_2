#include "date.hpp"

// ============================================================================

void read_date(FILE* in, date& out)
{
    fscanf(in, "%d.%d.%d", &out.year, &out.month, &out.day);
}

