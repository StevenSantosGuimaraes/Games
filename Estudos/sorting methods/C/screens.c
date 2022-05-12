#include "./screens.h"

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
