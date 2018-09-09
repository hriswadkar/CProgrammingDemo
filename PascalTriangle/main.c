#include<stdio.h>
#include<string.h>

int main() {
	char str[10];
	int len;
	int i, j;

	strcpy(str, "COBOL");
	len = strlen(str);

	printf("String is %s\n", str);
	printf("Length of string is %d\n", len);

	for(i=0;i<len;++i) {
		for(j=0;j<i;++j) {
			printf("%c ", str[j]);
		}
		printf("\n");
	}

	for(i=len;i>=0;--i) {
		for(j=0;j<=i;j++) {
			printf("%c ", str[j]);
		}
		printf("\n");
	}

	//getch();

	return 0;
}
