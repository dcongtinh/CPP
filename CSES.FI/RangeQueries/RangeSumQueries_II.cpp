#include <bits/stdc++.h>
#define maxN 200005

using namespace std;

int n, q;
int a[maxN];
long long f[maxN];

void update(int x, int val)
{
    while (x <= n)
    {
        f[x] += val;
        x += x & (-x);
    }
}

long long get(int x)
{
    long long ans = 0LL;
    while (x > 0)
    {
        ans += f[x];
        x -= x & (-x);
    }
    return ans;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(l, r - (get(l) - get(l - 1)));
        else
            cout << get(r) - get(l - 1) << endl;
    }
}