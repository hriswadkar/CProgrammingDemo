#include<stdio.h>
#include<stdlib.h>
#define MAX 3

void push();
void pop();
void display();

int stackArr1[5];
int stackArr2[5];
int top;


void main() {
    int found;
    int search;
    int selection;
    top = -1;


    do {
        printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n Enter your choice: ");
        scanf("%d", &selection);

        switch(selection) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting....");
            //System.exit(0);
            break;
        default:
            printf("\n Invalid choice");
            break;
        }
    } while(selection != 4);
}

void push() {
    int val;

    printf("\nEnter an element to push in stack\n");
    scanf("%d", &val);
    top++;

    if (top == MAX) {
        printf("Stack Overflow...");
        return;
    } else {
        top++;
        stackArr1[top] = val;
    }
}

void pop() {
    int val;

    if (stackArr1[top] == -1) {
        printf("\nStack Underflow...");
        return;
    } else {

    }
}

void display() {
}
