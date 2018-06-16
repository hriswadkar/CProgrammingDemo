#include<stdio.h>
#include<string.h>

int main() {
	int status;
	
	status = remove("fordel.txt");
	
	if(status == 0) {
		printf("\nFile deleted successfully");
	} else {
		printf("\n Error in deleting file");
	}
}
