#include<stdio.h>
#define SIZE 10

typedef struct {
    int item[SIZE];
    int top;
}Stack;

void push(Stack *, int);
int pop(Stack *);
void init(Stack *);


void push(Stack *sp, int value) {
    if (sp->top == SIZE - 1) {
        printf("\nSTACK OVERFLOW\n");
        return;
    }

    sp->top++;
    sp->item[sp->top] = value;
}

int pop(Stack *sp) {
    if (sp->top == -1) {
        printf("\nSTACK UNDERFLOW\n");
        return -9999;
    }

    int value;
    value = sp->item[sp->top];
    sp->top--;

    return value;
}

void init(Stack *sp) {
    sp->top = -1;
}

int main() {
    Stack sp1, sp2;
    init(&sp1);
    init(&sp2);

    push(&sp1, 100);
    push(&sp1, 200);

    push(&sp2, 10);
    push(&sp2, 20);

    printf("\nDeleted from s1 : %d\n", pop(&sp1));
    printf("\nDeleted from s1 : %d\n", pop(&sp1));

    printf("\nDeleted from s1 : %d\n", pop(&sp2));
    printf("\nDeleted from s1 : %d\n", pop(&sp2));

    return 0;
}
