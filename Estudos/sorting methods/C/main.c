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
                clearSystem();
                switch(screenSort()){
                    case 1:
                        break;
                }
                break;
            case 4:
                reset_values(values, length);
                printf("option 4 - Clean.\n");
                break;
            case 0:
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
        printf("|  3) Sort values;               |\n");
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
        printf("|  2) Insertio Sort;             |\n");
        printf("|  3) Selection Sort;            |\n");
        printf("|  4) Quick Sort;                |\n");
        printf("|                                |\n");
        printf("|  0) Return (Main Screen).      |\n");
        printf("|                                |\n");
        printf("|================================|\n");
        printf("|> ");
        scanf("%i", &option);
    }while(option < 0 && option > 4);
    return option;
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
