#include <stdio.h>

int searchArrElement(int *arr, int search, int size);

void main() {
    int array[] = { 61, 75, 83, 100, 30, 45, 86, 93, 29, 99 };
    int search;
    int arrSize;
    int found;

    printf("\nEnter element to search in the array.\n");
    scanf("%d", &search);
    arrSize = sizeof(array);

    found = searchArrElement(array, search, arrSize);
}

int searchArrElement(int *arr, int search, int size) {
    int i;
    int found = 0;

    for(i=0;i<size;i++) {
        if (arr[i] == search) {
            printf("\nElement %d is available in array at position %d", search, i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\n Element %d not found in array", search);
    }

    return found;
}
