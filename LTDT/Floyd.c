#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define oo 1e9

int d[MAX_N][MAX_N];

typedef struct
{
    int A[MAX_N][MAX_N];
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

void add_edge(Graph *pG, int x, int y)
{
    pG->A[x][y] = 1;
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

void Floyd(Graph *pG){
	int u, v, k, n = pG->n;
	for (k = 1; k <= n; ++k){
		for (u = 1; u <= n; ++u){
			for (v = 1; v <= n; ++v){
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, i = 1;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    int u, v;
    for (u = 1; u <= n; ++u){
    	for (v = 1; v <= n; ++v){
    		d[u][v] = oo;
    	}
    	d[u][u] = 0;
    }
    for (; i <= m; ++i)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add_edge(&G, u, v);
        add_edge(&G, v, u);
        d[u][v] = d[v][u] = c;
    }
    Floyd(&G);
    printf("%d", d[1][n] == oo ? -1 : d[1][n]);
}

