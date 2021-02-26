#include <stdio.h>
#include "ps2.h"

int main () {
    /* PS2.1 - Largest and Smallest */
    printf("===========================\n");
    printf("PS2.1: Largest and Smallest\n");
    printf("===========================\n");

    // declare input arrays, calculate length of arrays, inititalize largest and
    // smallest for both arrays
    const int array_1[] = {72,90,100,36,21,15,76,-6,63,41,99,27,3,66,19,16,27,47,0,23};
    int length_1 = sizeof(array_1) / sizeof(int);
    int largest_1, smallest_1;

    const int array_2[] = {-72,-90,-100,-36,-21,-15,-76,-6,63,41,99,27,3,66,19,16,27,47,0,23};
    int length_2 = sizeof(array_2) / sizeof(int);
    int largest_2, smallest_2;

    // call function on both arrays w/ necessary arguments
    large_and_small(array_1, length_1, &largest_1, &smallest_1);
    large_and_small(array_2, length_2, &largest_2, &smallest_2);

    // print value of largest and smallest ints in arrays
    printf("Array 1\n");
    printf("Largest: %i\n", largest_1);
    printf("Smallest: %i\n", smallest_1);

    printf("\n");

    printf("Array 2\n");
    printf("Largest: %i\n", largest_2);
    printf("Smallest: %i\n", smallest_2);


    /* PS2.2 - Inner Product */
    printf("====================\n");
    printf("PS2.2: Inner Product\n");
    printf("====================\n");

    // declare input arrays, calculate length of array based on left array
    const double left[] ={15.26, 28.20, 6.71, 72.22, 92.85, 15.50, 85.64, 57.41, 44.40, 72.91};
    const double right[] = {9.17, 4.8, 10.9, 10.12, 17.18, 3.9, 6.19, 5.4, 3.13, 6.1};
    int length = sizeof(left) / sizeof(double);

    // print value of call to inner product function
    printf("Result: %f\n", inner_product(left, right, length));


    /* PS2.3 - Same or Not the Same? */
    printf("====================\n");
    printf("PS2.3: Same or Not the Same?\n");
    printf("====================\n");

    // declare input arrays and calculate length of all arrays
    int left_2[] = {72,90,100,36,21,15,76,-6,63,41,99,27,3,66,19,16,27,47,0,23};
    int right_2[] = {72,90,100,36,21,15,76,-6,63,41,99,27,3,66,18,16,27,47,0,23};
    int left_2_length = sizeof(left_2) / sizeof(double);
    int right_2_length = sizeof(right_2) / sizeof(double);

    int left_3[] = {72,90,100,36,21,15,76,-6,63,41,99,27,3,66,19,16,27,47,0,23};
    int right_3[] = {72,90,100,36,21,15,76,-6,63,41,99,27,3,66,18,16,27,47,23};
    int left_3_length = sizeof(left_3) / sizeof(double);
    int right_3_length = sizeof(right_3) / sizeof(double);

    // call function and store results for both pairs of arraus
    bool results_2 = compareArrays(left_2, left_2_length, right_2, right_2_length);
    bool results_3 = compareArrays(left_3, left_3_length, right_3, right_3_length);

    // print out results, use a ternary operator to print out true or false
    printf("Result: %s\n", results_2 ? "true" : "false");
    printf("Result: %s\n", results_3 ? "true" : "false");

    return 0;
}