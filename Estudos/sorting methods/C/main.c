#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int quantity;
float array[TAM];

// screen and basic function:
void printValues(float vector[TAM], int quantity);
int menuMain();
char programShutDown();
void cleanScreen();

// bubble sort
// insertion sort
// selection sont
// quick sort

int main(){
    char answer = 'n';
    int option;
    while(answer != 's' || answer != 'S'){
        cleanScreen();
        option = menuMain();
        switch(option){
            case 1: //start
                printf("\nStart array...");
                break;
            case 2: //print
                printf("\nPrint array...");
                break;
            case 3: //sort
                printf("\nSort array values...");
                break;
            case 0: //close
                answer = programShutDown();
                break;
        }
    }
    cleanScreen();
    printf("\n=> Program ended successfully! <=");
}

void printValues(float vector[TAM], int quantity){
    int i;
    for(i = 0; i < quantity; i++){
        if(i == 0){
            printf("\nData: { %.2f", vector[i]);
        }else if(i == quantity - 1){
            printf("%.2f }.", vector[i]);
        }else{
            printf(", %.2f", vector[i]);
        }
    }
}

// bubble sort
// insertion sort
// selection sont
// quick sort

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

char programShutDown(){
    char option;
    do{
        printf("\nDo you want to close the program? (S/N) => ");
        scanf(" %c", &option);
    }while(option != 's' || option != 'S' || option != 'n' || option != 'N');
    return option;
}

void cleanScreen(){
    system("clear");
}
