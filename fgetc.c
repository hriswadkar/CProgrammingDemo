#include<stdio.h>
#include<string.h>

int main() {
	FILE *fptr;
	char ch;
	
	fptr = fopen("fprintdemo1.txt","r");
	
	if (fptr == NULL) {
		printf("Unable to open the file\n");
	} else {
		while(!feof(fptr)) {
			ch = fgetc(fptr);
			printf("%c", ch);
		}
	} 
}
