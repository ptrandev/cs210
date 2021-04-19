#include <stdio.h>
#include "rpn.h"
#include "stack.h"
#include "node.h"

int main() {
    int status;

    char expression_1[] = {"24.2 12 / 3 / 17 + +"};

    printf("EXPRESSION: %s\n", expression_1);
    printf("EVALUATION: %f\n", evaluate(expression_1, &status));
    printf("---\n");

    char expression_2[] = {"+"};

    printf("EXPRESSION: %s\n", expression_2);
    printf("EVALUATION: %f\n", evaluate(expression_2, &status));
    printf("---\n");

    char expression_3[] = {"17 22 / 4 * 16 -"};

    printf("EXPRESSION: %s\n", expression_3);
    printf("EVALUATION: %f\n", evaluate(expression_3, &status));
    printf("---\n");

    char expression_4[] = {"2 8 ^ 3 /"};

    printf("EXPRESSION: %s\n", expression_4);
    printf("EVALUATION: %f\n", evaluate(expression_4, &status));
    printf("---\n");

    char expression_5[] = {"17 22 33 / 4 + 2"};

    printf("EXPRESSION: %s\n", expression_5);
    printf("EVALUATION: %f\n", evaluate(expression_5, &status));
    printf("---\n");

    char expression_6[] = {""};

    printf("EXPRESSION: %s\n", expression_6);
    printf("EVALUATION: %f\n", evaluate(expression_6, &status));
    printf("---\n");

    char expression_7[] = {"8 7 + 6 - 5 / 4 * 3 ^"};

    printf("EXPRESSION: %s\n", expression_7);
    printf("EVALUATION: %f\n", evaluate(expression_7, &status));

    return 0;
}