#include<stdio.h>

int main() {
	int num;
	int *numptr;
	num = 100;
	numptr = &num;
	
	printf("Number is %d\n", num);
	printf("Pointer value is %d\n", *numptr);
	
	printf("Number is %d\n", &num);
	printf("Pointer value is %d\n", numptr);	
	
	getch();
}