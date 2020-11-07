#include <bits/stdc++.h>
#define maxN 200005
#define oo 1000000007

using namespace std;

int n, q;
int a[maxN], f[maxN];

void update(int x, int val)
{
    while (x <= n)
    {
        f[x] = min(f[x], val);
        x += x & (-x);
    }
}

int get(int l, int r)
{
    int ans = oo;
    while (r >= l)
    {
        if (r - (r & (-r)) >= l)
        {
            ans = min(ans, f[r]);
            r -= r & (-r);
        }
        else
        {
            ans = min(ans, a[r]);
            --r;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        f[i] = oo;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        update(i, a[i]);
    }
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", get(l, r));
    }
}