#include <bits/stdc++.h>
#define maxN 200005
#define oo 1000000007

using namespace std;

int n, q;
int a[maxN];

struct Node
{
    int val;
    int lazy;
    Node()
    {
        val = 0, lazy = 0;
    }
    Node(int v, int l)
    {
        val = v, lazy = l;
    }
};

Node node[4 * maxN];

Node operator+=(Node &a, int val)
{
    a.val += val;
    a.lazy += val;
    return a;
}

void initIT(int k, int l, int r)
{
    if (l == r)
    {
        node[k] = Node(a[l], 0);
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    node[k].val = min(node[2 * k].val, node[2 * k + 1].val);
}

void down(int k)
{
    int v = node[k].lazy;
    node[2 * k] += v;
    node[2 * k + 1] += v;
    node[k].lazy = 0;
}

void updateIT(int k, int l, int r, int u, int v, int val)
{
    // (u v) l, r (u v)
    if (v < l || r < u)
        return;
    // u (l, r) v
    if (u <= l && r <= v)
    {
        node[k] += val;
        return;
    }

    int m = (l + r) / 2;
    down(k);
    updateIT(2 * k, l, m, u, v, val);
    updateIT(2 * k + 1, m + 1, r, u, v, val);

    node[k].val = min(node[2 * k].val, node[2 * k + 1].val);
}

int queryIT(int k, int l, int r, int u, int v)
{

    // (u v) l, r (u v)
    if (v < l || r < u)
        return oo;
    // u (l, r) v
    if (u <= l && r <= v)
        return node[k].val;

    int m = (l + r) / 2;
    down(k);
    return min(queryIT(2 * k, l, m, u, v), queryIT(2 * k + 1, m + 1, r, u, v));
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    initIT(1, 1, n);
    while (q--)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
            updateIT(1, 1, n, l, l, r - queryIT(1, 1, n, l, l));
        else
            printf("%d\n", queryIT(1, 1, n, l, r));
    }
}