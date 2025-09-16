#include <stdio.h>

int main(void) { // wenn ohne void dann hei0t es dass die Funktion beliebige Argumente haben kann - frühere Versionen
    printf("Hello world");

    int var = 0;
    scanf("%i", &var);

    printf("Entered value: %i", var);

    return 0;
}