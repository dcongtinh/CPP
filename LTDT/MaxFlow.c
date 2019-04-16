    
#include <stdio.h>

#define oo 1e9
#define MAX_M 500

int s, t, front = 0, rear = 0;
int delta[MAX_M], f[MAX_M][MAX_M], trace[MAX_M], queue[MAX_M];

typedef struct {
    int u, v;
} Edge;

typedef struct {
    Edge edges[MAX_M];
    int n, m, c[MAX_M][MAX_M];
} Graph;

int min(int a, int b){ return a > b ? b : a; }
void push(int x){ queue[++rear] = x; }
int pop(){ return queue[++front]; }
int empty(){ return front >= rear; }

void init_graph(Graph *pG, int n, int m){
    pG->n = n, pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w){
    int m = pG->m;
    pG->edges[m].u = u;
    pG->edges[m].v = v;
    pG->c[u][v] = w;
    ++pG->m;
}

int adjacent(Graph *pG, int u, int v) {///u adjacent v
    int i;
    for (i = 0; i < pG->m; ++i){
        if (pG->edges[i].u == u && pG->edges[i].v == v)
            return 1;
    }
    return 0;
}

int FindPath(Graph *pG){
    int n = pG->n, u, v;
    for (u = 1; u <= n; ++u) trace[u] = 0;
    trace[s] = s;
    delta[s] = oo;
    push(s);
    while (!empty()){
        u = pop();
        for (v = 1; v <= n; ++v){
            if (adjacent(pG, u, v) && !trace[v]){
                if (pG->c[u][v] > f[u][v]){
                    trace[v] = u;
                    delta[v] = min(delta[u], pG->c[u][v] - f[u][v]);
                    push(v);
                } else if (f[v][u]){
                    trace[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    push(v);
                }
            }
        }
    }
    return trace[t];
}

void IncFlow(){
    int v = t;
    while (v != s){
        int u = trace[v];
        if (u > 0) f[u][v] += delta[t];
        else {
            u = -u;
            f[v][u] -= delta[t];
        }
        v = u;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    Graph G;
    int n, m, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (i = 0; i < m; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    s = 1; t = n;
    while (FindPath(&G)) IncFlow();
    int ans = 0, d1 = 0, d2 = 0;
    int X0[MAX_M], Y0[MAX_M];
    for (i = 1; i <= n-1; ++i) {
        ans += f[i][t];
        printf("%d %d\n", f[s][i], G.c[s][i]);
        if (f[i][t] && G.c[i][t] && f[i][t]-G.c[i][t]){
            Y0[++d2] = i;
        } else X0[++d1] = i;
    }
    Y0[++d2] = n;
    printf("Max flow: %d\n", ans);
    printf("X0: ");
    for (i = 1; i <= d1; ++i) printf("%d ", X0[i]);
    printf("\nY0: ");
    for (i = 1; i <= d2; ++i) printf("%d ", Y0[i]);
}