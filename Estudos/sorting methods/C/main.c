#include "main.h"

int main(){
    do{
        clearSystem();
        switch(screenMain()){
            case 1:
                do{
                    clearSystem();
                    printf("Enter the amount of data to be entered: ");
                    scanf("%d", &length);
                    values = (float *) malloc(length * sizeof(float));
                }while(length <= 0);
                break;
            case 2:
                print_values(values, length);
                break;
            case 3:
                insertValue(values, length);
                break;
            case 4:
                clearSystem();
                switch(screenSort()){
                    case 1:
                        printf("Before:");
                        print_values(values, length);
                        bubble_sort(values, length);
                        printf("After:");
                        print_values(values, length);
                        break;
                    case 2:
                        printf("\nSelection sort.");
                        break;
                    case 3:
                        printf("\nInsertion sort.");
                        break;
                    case 4:
                        printf("\nQuick sort.");
                        break;
                    case 0:
                        printf("\nReturned.");
                        break;
                    default:
                        printf("\nThe option informed is invalid, try again...");
                        break;
                }
                break;
            case 0:
                clearSystem();
                exit(1);
                break;
            default:
                printf("\nThe option informed is invalid, try again...");
                break;
        }
    }while(exit_program());
    clearSystem();
    printf("The program ended successfully.\n");
}

int screenMain(){
    int option;
    do{
        printf("|================================|\n");
        printf("|  > Main menu <                 |\n");
        printf("|--------------------------------|\n");
        printf("|                                |\n");
        printf("|  1) Start new vector;          |\n");
        printf("|  2) Print values;              |\n");
        printf("|  3) Insert values;             |\n");
        printf("|  4) Sort values;               |\n");
        printf("|                                |\n");
        printf("|                                |\n");
        printf("|  0) Exit.                      |\n");
        printf("|                                |\n");
        printf("|================================|\n");
        printf("|> ");
        scanf("%i", &option);
    }while(option < 0 && option > 3);
    return option;
}

int screenSort(){
    int option;
    do{
        printf("|================================|\n");
        printf("|  > Main menu > Sort Methods <  |\n");
        printf("|--------------------------------|\n");
        printf("|                                |\n");
        printf("|  1) Bubble Sort;               |\n");
        printf("|  2) Selection Sort;            |\n");
        printf("|  3) Insertion Sort;            |\n");
        printf("|  4) Quick Sort;                |\n");
        printf("|                                |\n");
        printf("|                                |\n");
        printf("|  0) Return (Main Screen).      |\n");
        printf("|                                |\n");
        printf("|================================|\n");
        printf("|> ");
        scanf("%i", &option);
    }while(option < 0 && option > 4);
    return option;
}
