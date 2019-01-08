// Example of functional macro
/*
	Program to find square of a number using macro
*/
#include<stdio.h>
#define SQUARE(x) (x * x)

int main() {
	int v, y;
	printf("\nEnter any number to find its square: ");
	scanf("%d", &v);
	y = SQUARE(v);
	printf("\nThe square of %d is %d\n", v, y);
	
	return 0;
}
