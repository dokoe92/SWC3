#include "str.h" // unter Anführungszeichen wird Datei zuerst im aktuellen Verzeichnis gesucht, Spitzklammern suchen zeurst wo Compiler liegt (besser für externe Bibliotheken)

#include <stdio.h>

int main() {
    str_t str = str_create("Hello, World");
    str_print(str);
    str_free(&str);

    printf("\nOK");


    return 0;
}