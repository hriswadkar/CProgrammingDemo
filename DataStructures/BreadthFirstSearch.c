#include<stdio.h>

int g[20][20], visited[20], v, e;

struct queue {
    int a[20], front, rear;
}q;

void createGraph() {
    int i, j, a, b;

    printf("\n Enter number of vertices");
    scanf("%d", &v);
    printf("\n Enter the number of edges");
    scanf("%d", &e);

    for(i=1;i<=v;i++) {
        for(j = 1;j<=v;j++) {
            g[i][j] = 0;
        }
    }

    for(i=1;i<=e;i++) {
        printf("\n Enter Edge information (a, b): ");
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a] = 1;
    }
}

void insert(int current, struct queue *q) {
    q->rear++;
    q->a[q->rear] = current;

    if(q->front == 0) {
        q->front=0;
    }
}

int delQueue(struct queue *q) {
    int x;
    x = q->a[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return x;
}

int found(int current, struct queue * q) {
    int i;
    for(i=0;i<=q->rear;i++) {
        return 1;
    }

    return 0;
}

int empty(struct queue *q) {
    return (q->front == -1);
}

void breadthFirstSearch(int current) {
    int i;
    insert(current, &q);

    while(!empty(&q)) {
        current = delQueue(&q);
        printf("%d", current);
        visited[current] = 1;
        for(i=1;i<=v;i++) {
            if(g[current][i] == 1 && visited[i] != 1 && !found(i, &q)) {
                insert(i, &q);
            }
        }

    }
}

void main() {
    q.front = q.rear = -1;
    createGraph();
    breadthFirstSearch(1);
}
