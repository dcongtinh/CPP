#include <bits/stdc++.h>

using namespace std;

int songuyento(int x)
{
	if (x < 2)
		return 0;
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void songuyento2(int x)
{
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
		{
			printf("NO");
			return;
		}
	}
	printf("YES");
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		if (songuyento(x))
			printf("%d YES\n", x);
		else
			printf("%d NO\n", x);
	}
}