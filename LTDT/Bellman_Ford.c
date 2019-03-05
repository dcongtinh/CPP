#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define oo 1e9

int n, m;
int d[MAX_N], trace[MAX_N];

struct List{
    int u, v, w;
} p[MAX_M];


void Bellman_Ford(int s){
    int u, v, w, k, i;
    for (u = 1; u <= n; ++u) d[u] = oo, trace[u] = -1;
    d[s] = 0;
	
    for (i = 1; i <= n; ++i){
        for (k = 1; k <= m; ++k){
            u = p[k].u; v = p[k].v; w = p[k].w;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                trace[v] = u;
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
    int i;
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
    }
    Bellman_Ford(1);
    for (u = 1; u <= n; ++u){
        printf("pi[%d] = %d, p[%d] = %d\n", u, d[u], u, trace[u]);
    }
    for (i = 1; i <= m; ++i){
        u = p[i].u; v = p[i].v; w = p[i].w;
        if (d[v] > d[u] + w) {
            printf("negative cycle");
            return 0;
        }
    }
    printf("ok");
}