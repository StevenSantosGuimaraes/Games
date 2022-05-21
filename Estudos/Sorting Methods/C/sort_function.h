#ifndef SORT_H
#define SORT_H

#include "main.h"

void swap_values(float *PtrValueA, float *PtrValueB);
void bubble_sort(float *array, int size);
void selection_sort(float *array, int size);
void insertion_sort(float *array, int size);
void quick_sort(float **array, int first, int last);

#endif
