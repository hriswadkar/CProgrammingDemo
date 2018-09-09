#include<stdio.h>

int main() {
	
	int size, i, j, k;
	
	printf("\nEnter size:\n");
	scanf("%d", &size);
	printf("\n\n");
	
	for(i = 1;i<=size;i++) {
		for(j = 1;j<=i;j++) {
			printf(" %d ", j);
		}		
		printf("\n");
	}
	
	printf("\n\n");
	
	for(i = 1;i<=size;i++) {
		for(j = 1;j<=i;j++) {
			for(k=1;k<j;k++) {
				printf(" %d ", j);	
			}
			
		}		
		printf("\n");
	}	
	
	return 0;
}
