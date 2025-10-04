
// #pragma once // Nicht standardisiert aber unterstützen eigentlich alle Compiler. Wenn man Bibliothek schreibt dann eher keine gute Idee

// iclude guard - Makro machen
#ifndef SWC3_STR_H
#define SWC3_STR_H 

#include <stddef.h>

typedef struct {
    size_t size;
    char* data;
} str_t;

str_t str_create(const char* initialvalue);
str_t str_createEmpty(size_t length);
void str_print(str_t s);
void str_free(str_t* s);

#endif