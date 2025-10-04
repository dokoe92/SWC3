#include <stdio.h>
#include <stdbool.h>

#define TITLE_LEN 50
#define NAME_LEN 50

typedef enum
{
    THRILLER,
    ROMANTIC,
    COMPUTER_SCIENCE
} Category;

set(SOURCES str.c main.c)
set(HEADERS str.h)


typedef struct
{
    int id;
    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    int birthyear;
} Author;

typedef struct
{
    int id;
    char title[TITLE_LEN];
    Author *authors;
    Category category;
} Book;


bool addBook()
{
    
}

void select_main_menu(void)
{
    printf("--Please select:\n");
    printf("1) Add new book\n");
    int selected;
    scanf("%i", &selected);
    switch (selected){
        case 1:
            addBook();
            break;
        }
}

void run_library() {
    Book* library = NULL;
    int book_count = 0;


    printf("### Library Management Software ###\n");
    printf("\n");
    select_main_menu();
}

int main(int argc, char *argv[])
{

    
}
