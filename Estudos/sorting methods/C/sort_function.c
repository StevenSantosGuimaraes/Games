#include "sort_function.h"

void swap_values(float *PtrValueA, float *PtrValueB){
    float auxiliary = *PtrValueA;
    *PtrValueA = *PtrValueB;
    *PtrValueB = auxiliary;
}

void bubble_sort(float *array, int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                swap_values(&array[j], &array[j + 1]);
            }
        }
    }
    printf("\nMethod sorting 'Bubble Sort' completed.");
}

void selection_sort(float *array, int size){

}

void insertion_sort(float *array, int size){

}

void quick_sort(float *array, int size){

}
