#include <bits/stdc++.h>
#define maxN 60007

using namespace std;

int n;
int a[maxN], node[4 * maxN];

void update(int k, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
        return;
    if (u <= l && r <= v)
    {
        node[k] += val;
        return;
    }
    int m = (l + r) / 2;
    update(2 * k, l, m, u, v, val);
    update(2 * k + 1, m + 1, r, u, v, val);
    node[k] = node[2 * k] + node[2 * k + 1];
}
int get(int k, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return node[k];
    int m = (l + r) / 2;
    return get(2 * k, l, m, u, v) + get(2 * k + 1, m + 1, r, u, v);
}
int main()
{
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int cnt = get(1, 1, m, 1, a[i] - 1);
        ans += cnt;
        update(1, 1, m, a[i], a[i], 1);
    }
    cout << ans;
}