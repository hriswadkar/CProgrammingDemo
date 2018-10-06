#include<stdio.h>

void main() {
    int i, j, n, a[20], temp, k, min_index;

    printf("\nEnter number of elements");
    scanf("%d",&n);
    printf("\nEnter the element: ");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++) {
        min_index=i;

        for(j=i+1;j<n;j++)
            if(a[j]<a[min_index]) {
                min_index=j;
            }
            if(i != min_index) {
                temp = a[i];
                a[i] = a[min_index];
                a[min_index] = temp;
            }
            printf("\n\n Pass %d ", (i+1));
            for(k=0;k<n;k++)
                printf(" %d ",a[k]);
    }

    printf("\n Sorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d ", a[i]);
}
