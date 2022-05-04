#include "./screen.h"

int menuMain(){
    int option;
    do{
        printf("\n|=================================|");
        printf("\n|  Please, enter a valid option:  |");
        printf("\n|---------------------------------|");
        printf("\n|                                 |");
        printf("\n|  1) Star new array;             |");
        printf("\n|  2) Print array;                |");
        printf("\n|  3) Select sort method;         |");
        printf("\n|                                 |");
        printf("\n|  0) Exit.                       |");
        printf("\n|                                 |");
        printf("\n|=================================|");
        scanf("%i", &option);
    }while(option != 0 || option != 1 || option != 2 || option != 3);
    return option;
}

void printArray(){

}
