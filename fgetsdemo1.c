#include<stdio.h>
#include<string.h>

int main() {
	FILE *fptr;
	char data[100];
	
	fptr = fopen("fgets.txt", "r");
	
	if(fptr == NULL) {
		printf("Unable to open file\n");
	} else {
		while(!feof(fptr)) {
			fgets(data, 50, fptr);
			printf("The data read is: %s\n", data);
		}
		
		fclose(fptr);
	}
	
	return 0;
}
