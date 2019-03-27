#include <stdio.h>

#define MAX_M 500
#define oo 1e9

int vector[MAX_M][MAX_M];
int c[MAX_M];

typedef struct
{
    int rank, vertex, c;
} Ranks;
Ranks p[MAX_M];

typedef struct
{
    int u, v;
} Edge;

typedef struct
{
    Edge edges[MAX_M];
    int n, m;
    int deg[MAX_M];
} Graph;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
void init_graph(Graph *pG, int n)
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
    ++pG->deg[v];
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
        if (pG->edges[i].u == u && pG->edges[i].v == v)
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

void ranking(Graph *pG)
{
    int k = 0, d = 0;
    ++vector[0][0];
    vector[0][1] = 1;
    p[0].rank = -1;
    p[0].vertex = 0;
    while (vector[k][0])
    {
        int i, u, v;
        for (i = 1; i <= vector[k][0]; ++i)
        {
            u = vector[k][i];
            p[++d].rank = k;
            p[d].vertex = u;
            for (v = 1; v <= pG->n; ++v)
            {
                if (adjacent(pG, u, v))
                {
                    --pG->deg[v];
                    if (!pG->deg[v])
                    {
                        int idx = ++vector[k + 1][0];
                        vector[k + 1][idx] = v;
                    }
                }
            }
        }
        ++k;
    }
}

Graph G;
int t[MAX_M], T[MAX_M];

int main()
{
	freopen("input.txt", "r", stdin);
    int n, u, i;
    scanf("%d", &n);
    init_graph(&G, n);
    for (u = 1; u <= n; ++u)
    {
        int v;
        scanf("%d", &c[u]);
        while (scanf("%d", &v) && v)
            add_edge(&G, v, u);
    }

    ranking(&G);
    p[n + 1].rank = p[n].rank + 1;
    p[n + 1].vertex = n + 1;
    add_edge(&G, p[n].vertex, n + 1);
    for (i = n - 1; i >= 1; --i)
    {
        if (p[i + 1].rank == p[i].rank)
            add_edge(&G, p[i].vertex, n + 1);
        else
            break;
    }
    ++n;

    t[0] = 0;
    for (i = 1; i <= n; ++i)
    {
        int u = p[i].vertex;
        int r = p[i].rank, j, _max = 0;
        for (j = 0; j < i; ++j)
        {
            int _u = p[j].vertex;
            int _r = p[j].rank;

            if (adjacent(&G, _u, u))
            {
                _max = max(_max, t[_u] + c[_u]);
            }
        }
        t[u] = _max;
    }
    T[n] = t[n];
    for (i = n - 1; i >= 0; --i)
    {
        int u = p[i].vertex, v, _min = oo;
        for (v = 1; v <= n; ++v)
        {
            if (adjacent(&G, u, v))
                _min = min(_min, T[v]);
        }
        T[u] = _min - c[u];
    }
    T[0] = 0;
    for (u = 1; u <= n+1; ++u){
    	if (t[u] == T[u]) printf("%d\n", u);
    }
    return 0;
}

