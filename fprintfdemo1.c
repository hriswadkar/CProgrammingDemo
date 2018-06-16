#include<stdio.h>
#include<string.h>

int main() {
	FILE *fptr;
	char name[25];
	int age;
	
	fptr = fopen("fprintdemo1.txt", "a");
	
	if (fptr == NULL) {
		printf("Error in opening the file");
	} else {
		printf("Enter your name and age\n");
		scanf("%s%d", name, &age);
		
		fprintf(fptr, "%s\t%d\n", name, age);
		printf("Data written successfully\n");
		
		fclose(fptr);
	}
	
	return 0;
}
