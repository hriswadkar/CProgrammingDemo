#include<stdio.h>
#include<string.h>

int main() {
	FILE *fptr, *fptr2;
	char str[25] = "Learning lad";
	int len = strlen(str);
	int counter;

	fptr = fopen("Hello2.txt","w");

	if(fptr == NULL) {
		printf("Unable to open the file\n");
	} else {
		for(counter=0;counter<len;counter++) {
			fputc(str[counter], fptr);
		}

		fclose(fptr);
	}

		fptr2 = fopen("Hello3.txt","a");

	if(fptr == NULL) {
		printf("Unable to open the file\n");
	} else {
		for(counter=0;counter<len;counter++) {
			fputc(str[counter], fptr2);
		}
		fputc('\n', fptr2);

		fclose(fptr2);
	}

}
