#include <stdio.h>
#define maxn 100

int weight, n = 1;
int f[maxn][maxn];

int max(int a, int b){
	return (a > b ? a : b);
}
struct Item{
	int weight, value;
	char name[maxn];
} items[maxn];

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &weight);
	while (scanf("%d%d%[^\n]", &items[n].weight, &items[n].value, items[n].name) != EOF) ++n;
	--n;
	int i, j, k;
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= weight; ++j){
			f[i][j] = f[i-1][j];
			if (items[i].weight <= j)
				f[i][j] = max(f[i][j], f[i-1][j-items[i].weight] + items[i].value);
		}
	}
	j = weight;
	printf("%d\n", f[n][weight]);
	for (i = n; i >= 1; --i){
		if (f[i][j] == f[i-1][j]) continue;
		printf("%d %d%s\n", items[i].weight, items[i].value, items[i].name);
		j -= items[i].weight;
	}
	return 0;
}
