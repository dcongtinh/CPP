#include <stdio.h>

#define MAX_N 100
#define MAX_M 500

typedef struct
{
    int data[MAX_N];
    int size;
} List;

typedef struct
{
    List adj[MAX_N]; //mảng các danh sách
    int n, m;
} Graph;

void init_graph(Graph *pG, int n, int m)
{
    int i;
    for (i = 1; i <= n; ++i)
        pG->adj[i].size = 0;
    pG->n = n;
    pG->m = m;
}

void add_edge(Graph *pG, int e, int x, int y)
{
    pG->adj[x].data[pG->adj[x].size++] = y;
    pG->adj[y].data[pG->adj[y].size++] = x;
}

int degree(Graph *pG, int x)
{
    return pG->adj[x].size;
}

int adjacent(Graph *pG, int x, int y) //A[x][e] == 1 && A[y][e] == 1
{
    int i;
    for (i = 1; i <= pG->adj[x].size; ++i)
    {
        if (pG->adj[x].data[i] == y)
            return 1;
    }
    return 0;
}

void neighbours(Graph *pG, int x)
{
    int i, n = pG->n;
    for (i = 1; i <= n; ++i)
    {
        if (adjacent(pG, x, i))
            printf("%d ", i);
    }
}

int main()
{
}