/*
    This program demonstrates Insertion Sort in C
*/
#include<stdio.h>
void main() {
    int i, j, n, y, a[20], k;
    printf("\nEnter the number of elements");
    scanf("%d",&n);
    printf("\nEnter the element");

    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    for(i=1;i<n;i++) {
        y=a[i];

        for(j=i-1;j>=0&&a[j]>y;j--)
            a[j+1]=a[j];

        a[j+1]=y;
        printf("\nPass %d: ", i);
        for(k=0;k<n;k++)
            printf("%d ", a[k]);
    }

    printf("\n\nSorted Array: ");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}
