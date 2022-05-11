#include "basic_function.h"

void clearSystem(){
    system("clear");
}

bool exit_program(){
    int answer;
    do{
        printf("\nDo you want to close the program? (1-Yes / 2-No)\n>>> ");
        scanf("%i", &answer);
    }while(answer != 1 && answer != 2);
    if(answer == 1){
        return false;
    }else{
        return true;
    }
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

void insertValue(float *array, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("Inform the %d. value: ", i + 1);
        scanf("%f", &array[i]);
    }
}
