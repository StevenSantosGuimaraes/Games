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
    printf("Method sorting 'Bubble Sort' completed.");
}

void selection_sort(float *array, int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if(array[j] < array[i]){
                swap_values(&array[j], &array[i]);
            }
        }
    }
    printf("Method sorting 'Selection Sort' completed.");
}

void insertion_sort(float *array, int size){
    int i, j;
    float auxiliary;
    for(i = 0; i < size; i++){
        printf("Inform the %d. value: ", i + 1);
        scanf("%f", &auxiliary);
        if(i == 0){
            array[i] = auxiliary;
        }else{
            for(j = i - 1; j >= 0 && array[j] > auxiliary; j--){
                array[j + 1] = array[j];
            }
            array[j + 1] = auxiliary;
        }
        print_values(array, size);
    }
    printf("Method sorting 'Insertion Sort' completed.");
}

void quick_sort(float *array, int size){

    printf("Method sorting 'Quick Sort' completed.");
}
