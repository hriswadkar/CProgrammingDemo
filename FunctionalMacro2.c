/* Program to illustrate various macro definitions */
#include<stdio.h>
#include<string.h>

#define STR1 "A macro definition!\n"
#define STR2 "must be all in one line!\n"
#define EXPR1 1+2+3
#define EXPR2 EXPR1+5
#define ABS(x) (((x) < 0) ? -(x):(x))
#define MAX(p,q) ((p < q) ? (q):(p))
#define BIGGEST(p,q,r) (MAX(p,q)<r)?(r):(MAX(p,q))

void main() {
    printf(STR1);
    printf(STR2);
    printf("\nLargest number among %d, %d and %d is %d\n", EXPR1, EXPR2, ABS(-3), BIGGEST(EXPR1,EXPR2,3));
    printf("\n%d", BIGGEST(3,5,2));
}
