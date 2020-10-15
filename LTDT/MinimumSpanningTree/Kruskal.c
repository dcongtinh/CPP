#include <stdio.h>

#define MAX_M 500
#define oo 1e9

int pset[MAX_M];
typedef struct {
	int u, v, w;
} Record;
Record p[MAX_M];

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
void init_set(int n)
{			
    int u;
    for (u = 1; u <= n; ++u)
		pset[u] = u;
}

int find_set(int u){
	return pset[u] == u ? u : (pset[u] = find_set(pset[u]));
}

int union_set(int u, int v){
	int x = find_set(u);
	int y = find_set(v);
	if (x != y) pset[x] = y;
}

int isSameSet(int u, int v){
	return find_set(u) == find_set(v);
}
void swapRecord(Record *a, Record *b){
	Record tmp = *a;
	*a = *b;
	*b = tmp;
}
void swapInt(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort(int m){
	int i, j;
	for (i = 1; i < m; ++i){
		for (j = i+1; j <= m; ++j){
			if (p[i].w > p[j].w){
				swapRecord(&p[i], &p[j]);
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
    int n, m, i;
    scanf("%d%d", &n, &m);
    init_set(n);
    for (i = 1; i <= m; ++i){
    	scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
    	if (p[i].u > p[i].v) swapInt(&p[i].u, &p[i].v);
    }
	sort(m);
	int weight = 0;
	int d = 0;
	Record list[MAX_M];
	for (i = 1; i <= m; ++i){
		int u = p[i].u;
		int v = p[i].v;
		int w = p[i].w;
		if (isSameSet(u, v)) continue;
		union_set(u, v);
		weight += w;
		list[++d] = p[i];
	}
	printf("%d\n", weight);
	for (i = 1; i <= d; ++i){
		printf("%d %d %d\n", list[i].u, list[i].v, list[i].w);
	}
    return 0;
}

