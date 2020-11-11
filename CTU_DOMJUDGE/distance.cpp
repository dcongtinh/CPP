#include <bits/stdc++.h>
#define maxN 100005
#define oo 1000000007

using namespace std;

int n, d;
int a[maxN];
pair<int, int> f[maxN];

void update(int x, int val)
{
    while (x <= n)
    {
        f[x].first = max(f[x].first, val);
        f[x].second = min(f[x].second, val);
        x += x & (-x);
    }
}

int get(int l, int r)
{
    int mx = 0, mn = oo;
    while (r >= l)
    {
        if (r - (r & (-r)) >= l)
        {
            mx = max(mx, f[r].first);
            mn = min(mn, f[r].second);
            r -= r & (-r);
        }
        else
        {
            mx = max(mx, a[r]);
            mn = min(mn, a[r]);
            --r;
        }
    }
    return mx - mn;
}

int main()
{

    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        f[i].first = 0;
        f[i].second = oo;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
        int diff = get(max(i - d + 1, 1), i);
        ans = max(ans, diff);
    }
    cout << ans << endl;
}