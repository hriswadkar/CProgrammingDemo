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

void dijkstra() {
    int source, dest, current, i, de, l, x, min;
    printf("Enter source & destination vertex: ");
    scanf("%d %d", &source, &dest);
    current = source;
    d[source] = 0;
    visited[source] = 1;
    de=d[current];

    while (visited[dest] != 1) {
        for(i=1;i<=v;i++) {
            if(g[current][i] != 0)
                if(visited[i] == 0)
            if (d[i] > g[current][i] + de) {
                d[i] = g[current][i] + de;
                p[i] = current;
            }
        }
        min = 32767;

        for(i=1;i<=v;i++) {
            if(visited[i] == 0)
            if(d[i] < min) {
                min = d[i];
                current=i;
            }
        }

        de=d[current];
        visited[current]=1;
    }

    printf("\nShortest distance from %d to %d\n", source, dest);
    printf("%d\n", d[dest]);
    printf("path = \n");
    l = dest;

    do {
        x = p[l];
        printf("Vertex %d connected to %d\n", l, x);
        l = x;
    } while(l != source);
}

void main() {
    CreateGraph();
    dijkstra();
}
