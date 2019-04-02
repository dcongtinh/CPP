#include <stdio.h>

#define MAX_M 500
#define oo 1e9

int cnt;
int c[MAX_M], vis[MAX_M], p[MAX_M];

typedef struct{
    int u, v;
} Edge;

typedef struct{
    Edge edges[MAX_M];
    int n, m;
    int pdeg[MAX_M], ndeg[MAX_M];
} Graph;

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}
void init_graph(Graph *pG, int n){
    pG->n = n, pG->m = 0;
}

void print_graph(Graph *pG){
    int n = pG->n, m = pG->m, i;
    printf("%d %d\n", n, m);
    for (i = 0; i < m; ++i){
        printf("%d %d\n", pG->edges[i].u, pG->edges[i].v);
    }
}

void add_edge(Graph *pG, int u, int v){
    int m = pG->m;
    pG->edges[m].u = u;
    pG->edges[m].v = v;
    ++pG->ndeg[u];
    ++pG->pdeg[v];
    ++pG->m;
}

int degree(Graph *pG, int u){
    int cnt = 0, i;
    for (i = 0; i < pG->m; ++i)
        cnt += (pG->edges[i].u == u || pG->edges[i].v == u);
    return cnt;
}

int adjacent(Graph *pG, int u, int v) {
    int i;
    for (i = 0; i < pG->m; ++i){
        if (pG->edges[i].u == u && pG->edges[i].v == v)
            return 1;
    }
    return 0;
}

void neighbours(Graph *pG, int x){
    int i;
    for (i = 1; i <= pG->n; ++i){
        if (adjacent(pG, x, i)) printf("%d ", i);
    }
}

void dfs(Graph *pG, int u){
    vis[u] = 1;
    int v;
    for (v = 1; v <= pG->n; ++v){
        if (!vis[v] && adjacent(pG, u, v))  dfs(pG, v);
    }
    p[cnt--] = u;
}

Graph G;
int t[MAX_M], T[MAX_M];

int main(){
    int n, u, v, i;
    scanf("%d", &n);
    init_graph(&G, n);
    for (u = 1; u <= n; ++u){
        scanf("%d", &c[u]);
        while (scanf("%d", &v) && v)
            add_edge(&G, v, u);
    }
    for (i = 1; i <= n; ++i){
        if (G.pdeg[i] == 0) add_edge(&G, 0, i);
        if (G.ndeg[i] == 0) add_edge(&G, i, n+1);
    }
    G.n = cnt = ++n;
    dfs(&G, 0);
    
    for (i = 0; i <= n; ++i){
        int u = p[i], v;
        for (v = 0; v <= n; ++v){
            if (adjacent(&G, u, v)){
                t[v] = max(t[v], t[u] + c[u]);
            } 
        }
    }
    for (i = 0; i <= n; ++i) T[i] = oo;
    T[n] = t[n];
    for (i = n; i >= 1; --i){
        int u = p[i], v;
        for (v = 0; v <= n; ++v){
            if (adjacent(&G, v, u)){
                T[v] = min(T[v], T[u] - c[v]);
            }
        }
    }
    printf("%d\n", t[n]);
    for (u = 1; u <= n - 1; ++u){
        printf("%d-%d\n", t[u], T[u]);
    }
    printf("%d-%d\n", t[0], T[0]);
    printf("%d-%d\n", t[n], T[n]);
    return 0;
}
