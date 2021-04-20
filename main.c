#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rpn.h"
#include "stack.h"
#include "node.h"
#include "converter.h"

int main(int argc, char* argv[]) {
    // error handling if correct amount of CLI arguemnts aren't given 
    if (argc < 3) {
        printf("missing argument(s)\n");
        return -1;
    }

    FILE * input = fopen(argv[1], "r"); // infix equations to process
    FILE *data = fopen(argv[2], "w"); // output of evaluations

    // handle error (file doesn't exist)
    if (!input) {
        perror("I/O error: ");
        return -1;
    }

    char dataLine[100]; // for storing input strings from file
    char *expression; // for storing postfix expression

    int status = 0; // status code
    double result = 0.0; // result of postfix expression evaluation

    // process each line of input file
    while (fgets(dataLine, 100, input)) {
        dataLine[strcspn(dataLine, "\n")] = 0; // remove trailing newline
        fprintf(data, "INFIX: %s\n", dataLine); // print infix notation to file
        
        // convert from infix to postfix notation
        expression = convertToPostfix(dataLine, &status);

        // if conversion is successful...
        if (expression != NULL) {
            fprintf(data, "POSTFIX: %s\n", expression); // print postfix notation to file

            // evaluate postfix expression and print result to file
            result = evaluate(expression, &status);
            fprintf(data, "RESULT: %f\n", result);
        }
        // else, print invalid input message to file
        else {
            fprintf(data, "POSTFIX: INVALID INPUT\n");
            fprintf(data, "RESULT: INVALID INPUT\n");
        }

        fprintf(data, "\n"); // print newline char to separate outputs
    }

    // close our files, done using them
    fclose(input);
    fclose(data);

    return 0;
}