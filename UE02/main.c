#include <stdio.h>
#include <string.h>

int main() {
    // const char* str = "Hello World";
    // printf("\n%s", str);
    // printf("\nStr ist %p, str zeigt auf %p", (*str), str);
    // printf("\nStr ist %p, str zeigt auf %p", (void*) str, str);

    const char str[10] = "Hello";

    printf("\n%s is at %p, size: %d", str, &str, sizeof(str));

    for (int i = 0; i < sizeof(str); i++) {
        printf("\n%i is at %p", i, (void*) (&str[i]));
    }

    const char* str1 = strdup("World");
    printf("\n%s is at %p, size: %d", str1, &str1, sizeof(str1));

    int len = strlen(str1) + strlen(str) + 1 + 1; // +1 Nul zeichen und +1 Leerzeichen
    char full[len];
    memset(full, 0, sizeof(full));

    strncat(full, str, strlen(str));

    printf("\nsizeof(full) = %d", sizeof(full));
    printf("\nfull = %s", full);

    {
        int res = strcmp(full, "Hello");
        printf("\nstrcmp(full, \"Hello\") = %d", res);
    }

    {
        int res = strcmp(full, "Pello");
        printf("\nstrcmp(full, \"Pello\") = %d", res);
    }

    snprintf(full, len, "%s %d", str1, sizeof(str1));
    printf("\nFull is now %s", full);



    return 0;

}