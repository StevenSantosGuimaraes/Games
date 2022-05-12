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
                        printf("\nBefore: ");
                        print_values(values, length);
                        bubble_sort(values, length);
                        printf("\nAfter: ");
                        print_values(values, length);
                        break;
                    case 2:
                        printf("\nBefore: ");
                        print_values(values, length);
                        selection_sort(values, length);
                        printf("\nAfter: ");
                        print_values(values, length);
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
