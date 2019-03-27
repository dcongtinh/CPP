#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define bool int
#define true 1
#define false 0

int vis[MAX_N];
int cycle = 0;
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

void dfs(Graph *pG, int u, int par){
	int v;
	vis[u] = 1;
	for (v = 1; v <= pG->n; ++v){
		if (adjacent(pG, u, v)){
            if (vis[v] == 0) dfs(pG, v, u);
            else if (vis[v] == 1 && v != par) cycle = 1;
		}
	}
    vis[u] = 2;
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
        add_edge(&G, u, v);
    }
    int u = 1;
    for (; u <= n; ++u){
        if (vis[u] == 0) {
            dfs(&G, u, 0);
        }
    }
    printf((cycle ? "YES" : "NO"));
}

