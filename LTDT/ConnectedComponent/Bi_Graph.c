#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define bool int
#define true 1
#define false 0

int color[MAX_N];
int conflict;

typedef struct
{
    int A[MAX_N][MAX_N];
    int n, m;
} Graph;

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
    pG->A[x][y] = pG->A[y][x] = 1;
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


int colorize(Graph* pG, int u, int c) {
	color[u] = c;
	int v;
	for (v = 1; v <= pG->n; ++v){
		if (adjacent(pG, u, v)) {
			if (c == color[v]) return 0;
			if (color[v] == -1 && !colorize(pG, v, !c)) return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, i = 1;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for (; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= n; ++i) color[i] = -1;
    if (!colorize(&G, 1, 0)) printf("IMPOSSIBLE");
    else {
    	int u;
    	for (u = 1; u <= n; ++u) {
    		if (color[u] == 0) printf("%d ", u);
    	}
    	printf("\n");
    	for (u = 1; u <= n; ++u) {
    		if (color[u] == 1) printf("%d ", u);
    	}
    }
}

