#include <stdio.h>

int n = 1, i, j;
int a[100][100], f[100][100];

int max(int a, int b){
	return (a > b ? a : b);
}
int main(){
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &a[n][1]) != EOF){
		for (i = 2; i <= n; ++i) scanf("%d", &a[n][i]);
		++n;
	}
	--n;
	f[1][1] = a[1][1];
	for (i = 2; i <= n; ++i){
		for (j = 1; j <= i; ++j){
			f[i][j] = max(f[i-1][j], max(f[i-1][j-1], f[i-1][j+1])) + a[i][j];
		}
	}
	int ans = 0, pos;
	for (j = 1; j <= n; ++j) ans = max(ans, f[n][j]);
	
	printf("%d", ans);
}
