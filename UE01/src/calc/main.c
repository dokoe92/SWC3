#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    CALC_ERR_NONE,
    CALC_ERR_INVALID_OP,
    CALC_ERR_DIVISION_BY_ZERO
} error_code_t;

error_code_t last_error = CALC_ERR_NONE;

double calculate(double a, double b, char op, bool* ok) {
    double result = 0;
    *ok = true;
    last_error = CALC_ERR_NONE;

    switch (op) {
        case '+':
            result = a + b; // es reicht wenn nur ein wert zu double konvertiert wird. 
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a *b;
            break;
        case '/':
            if (b ==0.0) {
                *ok = false;
                last_error = CALC_ERR_DIVISION_BY_ZERO;
            } else {
                result = a / b;
            }
            break;
        default:
            *ok = false;
            last_error = CALC_ERR_INVALID_OP;
            result = 0;
    }

    return result;
}

void print_usage(void) {
    printf("\nUsage: calc.exe\n");
    printf("\nOptions: ");
    printf("\n --help  Show this help");
    printf("\n\tEnter a op b!");
}

void print_last_error(void) {
    switch (last_error) {
        case CALC_ERR_NONE:
            printf("\nNo error");
            break;
        case CALC_ERR_DIVISION_BY_ZERO:
            printf("\nDivision by zero");
            break;
        case CALC_ERR_INVALID_OP:
            printf("\nInvalid operation");
            break;
    }
}

int main(int argc, char* argv[]) {

    printf("\nArgument count: %i\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %i: %s\n", i, argv[i]);
    }

    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        print_usage();
        return 1;
    }

    char command[50];
    bool exit_requested = false;

    while (!exit_requested) {
        printf("\nCalculator>");

        fgets(command, 50, stdin); // get aus file - hier aus stdin -> bei Start gibt es vordefinierte files (stdin, stdout, stderror)

        if (strncmp(command, "exit", 4) == 0 ||
            strncmp(command, "quit", 4) == 0) {
            exit_requested = true;
        } else if (strncmp(command, "help", 4) == 0) { // strncmp wegen leerzeichen ABER man könnte jetzt helphelp eingeben
            print_usage();
        } else {
            printf("Command is %s", command);

            double a = 0.0;
            double b = 0.0;
            char op = 0;

            int read_args = sscanf(command, "%lf %c %lf", &a, &op, &b);

            if (read_args != 3) {
                printf("\nFormat: a op b");
                continue;
            }

            bool ok = false;
            double result = calculate(a, b, op, &ok);

            if (!ok) {
                print_last_error();
            }

            printf("Result: %f\n", result);
        }
    }

    return 0;
}