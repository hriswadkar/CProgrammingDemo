#include<stdio.h>
#include<string.h>

int main() {
	
	FILE *fptr;
	char input[25]; 
	
	fptr = fopen("fputsdemo1.txt", "a");
	
	if(fptr == NULL) {
		printf("Unable to open the file");
	} else {
		printf("Enter string to be appended to file\n");
		gets(input);
		fputs(input, fptr);
		printf("User input written to file successfully\n");
		fclose(fptr);
	}
	
	
	return 0;
}
