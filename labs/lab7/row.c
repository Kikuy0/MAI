#include <stdlib.h>
#include <string.h>

#include "row.h"

struct row_t* DB_CreateRow(const char* name,
                           const char* description,
                           const char* country,
                           const char* exportc,
                           uint64_t    volume)
{
    struct row_t* row = malloc(sizeof(struct row_t));

    strncpy(row->name, name, 64);
    strncpy(row->description, description, 64);
    strncpy(row->country, country, 64);
    strncpy(row->exportc, exportc, 64);
    row->volume = volume;

    return row;
}
