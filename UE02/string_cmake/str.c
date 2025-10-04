#include "str.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <string.h>

str_t str_create(const char *initialValue)
{
    str_t result;

    result.size = strlen(initialValue);
    result.data = strdup(initialValue);

    return result;
}

str_t str_createEmpty(size_t length)
{
    str_t result;

    result.size = length;
    result.data = malloc(sizeof(char) * (length + 1));

    assert(result.data != NULL);

    memset(result.data, 0, sizeof(char) * (length + 1));

    return result;
}

void str_print(str_t s)
{
    assert(s.data != NULL);
    printf("%s", s.data); // Achtung wird immer am Stack kopiert kann langsam werden wenn sauviele Daten
}

void str_free(str_t *s)
{
    if (s != NULL)
    {
        free(s->data);
        s->size = 0;
    }
}