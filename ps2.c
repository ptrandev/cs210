#include <stdio.h>
#include "ps2.h"

void large_and_small(const int* array, int length, int* largest, int* smallest) {
    // assign values of largest and smallest to value of first item in array
    *largest = *array;
    *smallest = *array;

    // loop through every item in array via pointer arithmetic
    for(; length != 0; length--, array++) {
        // if the current item larger than current largest...
        // else if current item smaller that current smallest...
        if (*array > *largest) {
            *largest = *array; // reassign value of largest to current item
        } else if (*array < *smallest) {
            *smallest = *array; // reassign value of largest to smallest item
        }
    }

    // method void, so we don't return anything
    return;
}

double inner_product(const double* leftArray, const double* right_array, int length) {
    // initialze double to store result of inner product
    double result = 0.0;

    // loop through both arrays simultaneously to perform inner product
    for(; length != 0; length--, leftArray++, right_array++) {
        // add product of current item in left and right array to result
        result += *leftArray * *right_array;
    }

    return result;
}

bool compareArrays(int* left, int left_length, int* right, int right_length) {
    // if the arrays are different length, they can't be the same array
    if (left_length != right_length) {
        return false;
    }

    // loop through both arrays simultaneously, since arrays are the same length
    // we only need to use one of the array's lengths as a counter
    for(; left_length != 0; left_length--, left++, right++) {
        // if the items in the left and right don't match, return false
        if (*left != *right) {
            return false;
        }
    }

    // if entire array is looped through, then the arrays must be the same
    return true;
}