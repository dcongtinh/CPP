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
        f[x] ^= val;
        x += x & (-x);
    }
}

long long get(int x)
{
    long long ans;
    ans = f[x];
    x -= x & (-x);
    while (x > 0)
    {
        ans ^= f[x];
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
        f[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        update(i, a[i]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << endl;
    }
}