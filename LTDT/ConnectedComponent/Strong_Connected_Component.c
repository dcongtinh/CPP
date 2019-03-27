#include <stdio.h>
#include <math.h>
#define MAX_N 100
#define MAX_M 500
#define bool int
#define true 1
#define false 0

int vis[MAX_N], stack[MAX_N], low[MAX_N], num[MAX_N];
int top, dfsCount, scc;

typedef struct
{
    int A[MAX_N][MAX_N];
    int n, m;
} Graph;

int min(int a, int b){
	if (a < b) return a;
	return b;
}

void push(int x){
    stack[top++] = x;
}

int pop(){
    return stack[--top];
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

void visit(Graph *pG, int u){
	int v;
	low[u] = num[u] = ++dfsCount;
	push(u);
	for (v = 1; v <= pG->n; ++v){
		if (adjacent(pG, u, v)){
            if (vis[v] == 0) {
            	if (num[v] == 0) {
            		visit(pG, v);
            		low[u] = min(low[u], low[v]);
            	} else low[u] = min(low[u], num[v]);
            }
            
		}
	}
	if (num[u] == low[u]){
		++scc;
		do {
			v = pop();
			vis[v] = 1;
		} while (v != u);
	}
}


int main()
{
// 	freopen("input.txt", "r", stdin);
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
    int u = 1;
    for (; u <= n; ++u){
        if (vis[u] == 0) {
            visit(&G, u);
        }
    }
    if (scc == 1) printf("strong connected");
    else printf("unconnected");
}

