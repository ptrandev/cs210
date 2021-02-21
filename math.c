#include "math.h"

float add(float num_1, float num_2) {
    float result = num_1 + num_2;
    return result;
}

float subtract(float num_1, float num_2) {
    float result = num_1 - num_2;
    return result;
}

float multiply(float num_1, float num_2) {
    float result = num_1 * num_2;
    return result;
}

float divide(float num_1, float num_2) {
    float result = num_1 / num_2;
    return result;
}

float power(float num_1, float num_2) {
    float result = num_1;

    for (int i = 1; i < num_2; i++) {
        result *= num_1;
    }

    return result;
}

float recursivePower(float num_1, float num_2) {
    if (num_2 == 1) {
        return num_1;
    }

    return num_1 * recursivePower(num_1, num_2 - 1);
}