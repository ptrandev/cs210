#include <stdbool.h> 

#ifndef FUNCTIONS_PS2_H
#define FUNCTIONS_PS2_H

void large_and_small(const int* array, int length, int* largest, int* smallest);
double inner_product(const double* leftArray, const double* right_array, int length);
bool compareArrays(int* left, int left_length, int* right, int right_length);

#endif // FUNCTIONS_PS2_H