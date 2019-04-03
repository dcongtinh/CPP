#include <stdio.h>

int n, i, j, ans;
int a[100][100], vis[100], p[100];

int max(int a, int b){
	return (a > b ? a : b);
}

void permutation(int i){
	if (i > n){
		int k, s = 0;
		for (k = 1; k <= n; ++k) s += a[k][p[k]];
		ans = max(ans, s);
		return;
	}
	int j;
	for (j = 1; j <= n; ++j){
		if (!vis[j]){
			p[i] = j;
			vis[j] = 1;
			permutation(i+1);
			vis[j] = 0;
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	}
	permutation(1);
	printf("%d", ans);
	return 0;
}
