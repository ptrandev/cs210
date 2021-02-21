#include <stdio.h>
#include "math.h"

int main() {
    float num_1, num_2, result;
    char operator;

    do {
        printf("Enter the equation: ");
        scanf(" %f%c%f", &num_1, &operator, &num_2);

        switch (operator) {
            case '+':
                result = add(num_1, num_2);
                break;
            case '-':
                result = subtract(num_1, num_2);
                break;
            case '*':
                result = multiply(num_1, num_2);
                break;
            case '/':
                result = divide(num_1, num_2);
                break;
            case '^':
                result = power(num_1, num_2);
                break;
            case '$':
                result = recursivePower(num_1, num_2);
                break;
        }

        printf("Result: %.2f \n", result);

    } while (1);

    return 0;
}