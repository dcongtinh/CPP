#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define bool int
#define true 1
#define false 0

bool vis[MAX_N];
typedef struct {
    int u, v;
} Edge;


typedef struct {
    Edge edges[MAX_M];
    int n, m;
} Graph;

typedef struct {
    int top;
    int A[MAX_N];
} Stack;

void make_null_stack(Stack *S){
    S->top = 0;
}

void push(Stack *S, int x){
    S->A[S->top++] = x;
}

int pop(Stack *Q){
    return Q->A[--Q->top];
}

int empty(Stack *Q){
    return (Q->top == 0);
}

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

void dfs(Graph *pG, int u){
    Stack s;
    make_null_stack(&s);
    push(&s, u);
    while (!empty(&s)){
        int u = pop(&s), v;
        if (vis[u]) continue;
        vis[u] = true;
        // printf("%d\n", u);
        for (v = 1; v <= pG->n; ++v){
            if (adjacent(pG, u, v)) push(&s, v);
        }
    }
}

int main()
{
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    int i;
    for (i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    int u = 1;
    int cnt = 0;
    for (; u <= n; ++u){
        if (!vis[u]){
            ++cnt;
            dfs(&G, u);
        }
    }
    printf((cnt == 1 ? "YES" : "NO"));
}