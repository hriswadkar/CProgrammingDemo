#include<stdio.h>
#include<string.h>

int main() {
	FILE *fptr;
	char msg1[10];
	char msg2[20];
	int age;
	
	fptr = fopen("fscanf.txt", "r");
	
	if(fptr == NULL) {
		printf("Unable to open the file\n");
	} else {
		fscanf(fptr, "%s %d", msg1, &age);
		
		printf("%s\t%d\n", msg1, age);
		
		fclose(fptr);
	}
}
