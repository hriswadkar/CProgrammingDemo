#include<stdio.h>
#include<stdbool.h>

#define MAX 10

int top, stackArr[MAX];
void push();
void pop();
void display();

void main() {
    int ch;
    top = -1;

    do {
        printf("\n Press \n 1: Push \n 2: Pop \n 3: Display \n 4: Exit");
        printf("\n Your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
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
            printf("\n Exiting");
            break;
        default:
            printf("\n Invalid Choice");
            break;
        }
    } while(ch != 4);
}

void push() {
    int x;
    if (top == MAX - 1) {
        printf("\n Stack Overflow");
        return;
    }

    printf("\n Enter a number");
    scanf("%d", &x);
    top++;
    stackArr[top] = x;

    printf("\n Element %d successfully pushed in stack\n", x);

    return;
}

void pop() {
    int y;
    if (top == -1) {
        printf("\n Stack Underflow");
        return;
    }

    y = stackArr[top];
    stackArr[top]=0;
    top--;

    printf("\n Element %d is successfully popped\n", y);

    return;
}

void display() {
    int i;
    if (top == -1) {
        printf("\n Stack is empty");
        return;
    } else {
        printf("\n Elements of stack array are: \n");
        for(i=0;i<=top;i++) {
            printf("%d\n", stackArr[i]);
        }

        printf("\n\n\n");
        for(i=top;i>=0;i--) {
            printf("%d\n", stackArr[i]);
        }
    }

    return;
}
