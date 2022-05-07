#include <stdio.h>
#include <stdlib.h>

// Methods:
// Bubble_sort;
// selection_sort;
// insertion_sort;
// quick_sort.

// swap(array, a , b)

void clearSystem();
void pauseSystem();

int main(){
    clearSystem();
    printf("Test.\n");
    pauseSystem();
}

void clearSystem(){
    system("clear");
}

void pauseSystem(){
    printf("Press any key to continue...");
    getchar();
}
