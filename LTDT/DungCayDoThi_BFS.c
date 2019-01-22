#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define bool int
#define true 1
#define false 0

bool vis[MAX_N];
int parent[MAX_N];

typedef struct {
    int u, v;
} Edge;


typedef struct {
    Edge edges[MAX_M];
    int n, m;
} Graph;

typedef struct {
    int front, rear;
    int A[MAX_N];
} Queue;

void make_null_queue(Queue *Q){
    Q->front = Q->rear = 0;
}

void push(Queue *Q, int x){
    Q->A[Q->rear++] = x;
}

int pop(Queue *Q){
    return Q->A[Q->front++];
}

int empty(Queue *Q){
    return (Q->front == Q->rear);
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

void bfs(Graph *pG, int u){
    Queue q;
    make_null_queue(&q);
    push(&q, u);
    vis[u] = true;
    // printf("%d\n", u);
    while (!empty(&q)){
        int u = pop(&q), v;
        for (v = 1; v <= pG->n; ++v){
            if (adjacent(pG, u, v) && !vis[v]){
                vis[v] = true;
                // printf("%d\n", v);
                parent[v] = u;
                push(&q, v);
            }
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
    for (; u <= n; ++u){
        if (!vis[u]){
            bfs(&G, u);
        }
    }
    for (u = 1; u <= n; ++u){
        printf("%d %d\n", u, parent[u]);
    }
}