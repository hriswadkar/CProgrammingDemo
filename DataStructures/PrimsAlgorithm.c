#include<stdio.h>

int g[20][20], visited[20], d[20], p[20];
int v, e;

void CreateGraph() {
    int i, j, a, b, w;

    printf("\nEnter number of vertices: ");
    scanf("%d",&v);
    printf("\nEnter number of edges: ");
    scanf("%d",&e);

    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            g[i][j] = 0;

    for(i=1;i<=v;i++) {
        p[i] = visited[i] = 0;
        d[i] = 32767;
    }

    for(i=1;i<=e;i++) {
        printf("\n Enter edge (a, b) and weight w: ");
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = g[b][a] = w;
    }
}

void prim() {
    int current, totalVisited, mincost, i, min;

    current = 1;
    d[current]=0;
    totalVisited=1;
    visited[current]=1;

    while(totalVisited != v) {
        for(i=1;i<v;i++) {
            if(g[current][i] != 0)
                if(visited[i] == 0)
            if (d[i] > g[current][i]) {
                d[i] = g[current][i];
                p[i] = current;
            }
        }
        min = 32767;
        for(i=1;i<=v;i++) {
            if (visited[i] == 0)
            if (d[i] < min) {
                min = d[i];
                current = i;
            }
        }
        visited[current] = 1;
        totalVisited++;
    }

    mincost = 0;
    for(i=1;i<=v;i++) {
        mincost += d[i];
    }

    printf("\nMinimum Cost = %d \n", mincost);
    printf("Minimum Span tree is \n");

    for(i=1;i<=v;i++)
        printf("Vertex %d is connected to %d\n", i, p[i]);
}

void main() {
    CreateGraph();
    prim();
}
