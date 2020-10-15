#include <stdio.h>
#define maxn 100

int weight, n = 1;
int f[maxn][maxn], trace[maxn][maxn];

int max(int a, int b)
{
	return (a > b ? a : b);
}
struct Item
{
	int count, weight, value;
	char name[maxn];
} items[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &weight);
	while (scanf("%d%d%d%[^\n]", &items[n].count, &items[n].weight, &items[n].value, items[n].name) != EOF)
		++n;
	--n;
	int i, j, k, v;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= weight; ++j)
		{
			f[i][j] = f[i - 1][j];
			for (k = 1; k <= items[i].count && j >= k * items[i].weight; ++k)
			{
				if (f[i][j] < f[i - 1][j - k * items[i].weight] + k * items[i].value)
				{
					f[i][j] = f[i - 1][j - k * items[i].weight] + k * items[i].value;
					trace[i][j] = k;
				}
			}
		}
	}
	j = weight;
	v = f[n][weight];
	printf("%d\n", f[n][weight]);
	for (i = n; i >= 1; --i)
	{
		if (f[i][j] == f[i - 1][j])
			continue;
		printf("%d %d %d%s\n", k, items[i].weight, items[i].value, items[i].name);
		j -= trace[i][j] * items[i].weight;
	}
	return 0;
}
