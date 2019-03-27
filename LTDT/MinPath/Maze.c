#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define oo 1e9

int d[MAX_N], vis[MAX_N], cnt[MAX_N], label[MAX_N][MAX_N], c[MAX_N][MAX_N], trace[MAX_N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

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
    d[s] = c[s][s];
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
                d[v] = min(d[v], d[u] + pG->W[u][v]);
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
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n*m);
    int u, v, t = 0;
    for (i = 1; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            int w;
            scanf("%d", &w);
            label[i][j] = ++t;
            c[i][j] = w;
        }
    }

    for (i = 1; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            int k;
            for (k = 0; k <= 3; ++k){
                int x = i + dx[k];
                int y = j + dy[k];
                if (1 <= x && x <= n && 1 <= y && y <= m){
                    add_edge(&G, label[i][j], label[x][y], c[x][y]);
                    add_edge(&G, label[x][y], label[i][j], c[i][j]);
                    // printf("%d %d %d\n", label[i][j], label[x][y], c[x][y]);
                }
            }
        }
    }
    Dijkstra(&G, 1);
    printf("%d", d[t]);
    // for (i = 1; i <=t; ++i) printf("%d ", d[i]);
}