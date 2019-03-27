#include <stdio.h>

#define MAX_M 500
#define oo 1e9

int vis[MAX_M];

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

void dfs(Graph *pG, int u){
	vis[u] = 1;
	int v;
	for (v = 1; v <= pG->n; ++v){
		if (adjacent(pG, u, v) && !vis[v]) dfs(pG, v);
	}
	printf("%d ", u);
}
Graph G;

int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, u, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, v, u);
    }
	for (u = 1; u <= n; ++u){
		if (!vis[u]) dfs(&G, u);
	}
    return 0;
}

