#include "basic_function.h"

void clearSystem(){
    system("clear");
}

void print_values(float *array, int size){
    int i;
    for(i = 0; i < size; i++){
        if(i == 0){
            printf("Values: { %.2f", array[i]);
        }else if(i == size - 1){
            printf(", %.2f }.", array[i]);
        }else{
            printf(", %.2f", array[i]);
        }
    }
}

void reset_values(float *array, int size){
    int i;
    for(i = 0; i < size; i++){
        (&array)[i] = 0;
    }
    printf("\nValues changed to ZERO.");
}
