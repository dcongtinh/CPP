#include <stdio.h>

#define MAX_M 500

typedef struct {
    int u, v;
} Edge;


typedef struct {
    Edge edges[MAX_M];
    int n, m;
} Graph;

void init_graph(Graph *pG, int n, int m)
{
    pG->n = n, pG->m = 0;
}

void print_graph(Graph *pG)
{
    int n = pG->n, m = pG->m, i;
    printf("%d %d\n", n, m);
    for (i = 0; i < m; ++i)
    {
        printf("%d %d\n", pG->edges[i].u, pG->edges[i].v);
    }
}

void add_edge(Graph *pG, int u, int v)
{
    int m = pG->m;
    pG->edges[m].u = u;
    pG->edges[m].v = v;
    ++pG->m;
}

int degree(Graph *pG, int u)
{
    int cnt = 0, i;
    for (i = 0; i < pG->m; ++i)
        cnt += (pG->edges[i].u == u || pG->edges[i].v == u);
    return cnt;
}

int adjacent(Graph *pG, int u, int v) ///u adjacent v
{
    int i;
    for (i = 0; i < pG->m; ++i)
    {
        if ((pG->edges[i].u == u && pG->edges[i].v == v) || (pG->edges[i].v == u && pG->edges[i].u == v))
            return 1;
    }
    return 0;
}

void neighbours(Graph *pG, int x)
{
    int i;
    for (i = 1; i <= pG->n; ++i)
    {
        if (adjacent(pG, x, i))
            printf("%d ", i);
    }
}
int main()
{
    Graph G;
    int n, m, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    print_graph(&G);
}
