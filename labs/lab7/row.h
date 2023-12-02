#ifndef ROW_H
#define ROW_H

#include <stdint.h>

struct row_t
{
    char     name[64];
    char     description[64];
    char     country[64];
    char     exportc[64];
    uint64_t volume;
};

/*
 * создает запись и возвращает укаазатель
 * использует malloc
 */
struct row_t* DB_CreateRow(const char* name,
                           const char* description,
                           const char* country,
                           const char* exportc,
                           uint64_t    volume);

#endif
