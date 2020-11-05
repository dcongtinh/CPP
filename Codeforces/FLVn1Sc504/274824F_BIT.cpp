#include <bits/stdc++.h>
#define maxN 60007

using namespace std;

int n, m = 0;
int a[maxN], f[maxN];

void update(int x, int val)
{
    while (x <= m)
    {
        f[x] += val;
        x += x & (-x);
    }
}

int get(int x)
{
    int ans = 0;
    while (x)
    {
        ans += f[x];
        x -= x & (-x);
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        update(a[i], 1);
        ans += get(a[i]-1);
    }
    cout << ans;
}