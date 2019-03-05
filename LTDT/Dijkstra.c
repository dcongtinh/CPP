#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define oo 1e9

int d[MAX_N], vis[MAX_N], cnt[MAX_N], trace[MAX_N];

typedef struct
{
    int A[MAX_N][MAX_N], W[MAX_N][MAX_N];
    int n, m;
} Graph;

int min(int a, int b){
	if (a < b) return a;
	return b;
}

void init_graph(Graph *pG, int n)
{
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            pG->A[i][j] = 0;
    }
    pG->n = n;
}

void add_edge(Graph *pG, int x, int y, int z)
{
    pG->A[x][y] = 1;
    pG->W[x][y] = z;
}

int degree(Graph *pG, int x)
{
    int i, cnt = 0;
    for (i = 1; i <= pG->n; ++i)
        cnt += pG->A[x][i];
    return cnt;
}

int adjacent(Graph *pG, int x, int y)
{
    return (pG->A[x][y]);
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

void print_graph(Graph *pG)
{
    int i, j, n = pG->n;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%d ", pG->A[i][j]);
        printf("\n");
    }
}

void Dijkstra(Graph *pG, int s){
	int u, v, k, it, n = pG->n;
    for (u = 1; u <= n; ++u) d[u] = oo, vis[u] = 0;
    d[s] = 0;
    cnt[s] = 1;
	for (it = 1; it <= n; ++it){
        int i, minVal = oo;
        for (i = 1; i <= n; ++i){
            if (!vis[i] && d[i] < minVal){
                minVal = d[i];
                u = i;
            }
        }
        vis[u] = 1;
        for (v = 1; v <= n; ++v){
            if (adjacent(pG, u, v) && !vis[v]){
                if (d[u] + pG->W[u][v] <= d[v]){
                    if (d[u] + pG->W[u][v] == d[v]) cnt[v] += cnt[u];
                    else cnt[v] = cnt[u];
                    d[v] = d[u] + pG->W[u][v];
                    trace[v] = u;
                }
            }
        }
    }
}

void print_path(int u){
    if (!u) return;
    print_path(trace[u]);
    printf("%d ", u);
}

int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, i;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    int u, v;
    for (i = 1; i <= m; ++i)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add_edge(&G, u, v, c);
        add_edge(&G, v, u, c);
    }
    Dijkstra(&G, 1);
    printf("Min length: %d, total min path: %d\n", d[n], cnt[n]);
    print_path(n);

}