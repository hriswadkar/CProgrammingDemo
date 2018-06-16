#include<stdio.h>
#include<string.h>

int main() {
	if(rename("oldname.txt", "newname.txt") == 0) {
		printf("\nfile renamed successfully");
	} else {
		printf("\n unable to rename file");
	}
}
