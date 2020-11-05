#include <bits/stdc++.h>
#define ll long long
#define maxN 1000005

using namespace std;

int n, q;
int a[maxN];
ll f[maxN];

void update(int x, int inc)
{
    while (x <= n)
    {
        f[x] += inc;
        x += x & (-x);
    }
}

ll get(int x)
{
    ll ans = 0LL;
    while (x > 0)
    {
        ans += f[x];
        x -= x & (-x);
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    cin >> q;
    while (q--)
    {
        char t;
        int i, l, r, k;
        cin >> t;
        if (t == 'u')
        {
            cin >> i >> k;
            update(i, k);
        }
        else
        {
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
    }
}
