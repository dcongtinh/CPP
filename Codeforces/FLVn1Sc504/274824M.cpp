#include <bits/stdc++.h>
#define maxN 500005
#define oo 1000000007

using namespace std;

int n, q;
int a[maxN];

struct Node
{
    int mx;
    int mn;
    Node()
    {
        mx = -oo, mn = oo;
    }
    Node(int a, int b)
    {
        mx = a, mn = b;
    }
};

Node node[4 * maxN];

Node comprare(Node a, Node b)
{
    int mx = max(a.mx, b.mx);
    int mn = min(a.mn, b.mn);
    return Node(mx, mn);
}

void initIT(int k, int l, int r)
{
    if (l == r)
    {
        node[k] = Node(a[l], a[l]);
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    node[k] = comprare(node[2 * k], node[2 * k + 1]);
}

Node queryIT(int k, int l, int r, int u, int v)
{

    // (u v) l, r (u v)
    if (v < l || r < u)
        return Node(-oo, oo);
    // u (l, r) v
    if (u <= l && r <= v)
        return node[k];

    int m = (l + r) / 2;
    return comprare(queryIT(2 * k, l, m, u, v), queryIT(2 * k + 1, m + 1, r, u, v));
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    initIT(1, 1, n);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        Node ans = queryIT(1, 1, n, u, v);
        cout << ans.mx - ans.mn << endl;
    }
}