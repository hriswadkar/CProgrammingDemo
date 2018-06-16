#include<stdio.h>
#include<conio.h>

int main() {

/*
    This program creates a file
*/

    FILE *fptr, *fptr2, *fptr3;
    //clrscr();
    fptr = fopen("hello.txt", "r");

    if(fptr == NULL) {
        printf("Unable to open the file");
    } else {
        printf("File opened successfully");
    }

    fptr2 = fopen("hello2.txt","w");

    if(fptr2 == NULL) {
        printf("Unable to open the file");
    } else {
        printf("File opened successfully");
    }

    fptr3 = fopen("hello2.txt","a");

    if(fptr3 == NULL) {
        printf("Unable to open the file");
    } else {
        printf("File opened successfully");
    }

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);



    getch();
    return 0;
}
