#include <stdio.h>

#define MAX_N 100

typedef struct
{
    int A[MAX_N][MAX_N];
    int n, m;
} Graph;

void init_graph(Graph *pG, int n, int m)
{
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
            pG->A[i][j] = 0;
    }
    pG->n = n;
    pG->m = m;
}

void add_edge(Graph *pG, int e, int x, int y)
{
    pG->A[x][e] = pG->A[y][e] = 1;
}

int degree(Graph *pG, int x)
{
    int i, cnt = 0;
    for (i = 1; i <= pG->m; ++i)
        cnt += pG->A[x][i];
    return cnt;
}

int adjacent(Graph *pG, int x, int y) //A[x][e] == 1 && A[y][e] == 1
{
    int i, cnt = 0;
    for (i = 1; i <= pG->m; ++i)
    {
        if (pG->A[x][i] * pG->A[y][i] == 1)
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
    int n, m, i = 1;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n, m);
    for (; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, i, u, v);
    }
}