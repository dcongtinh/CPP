#include <bits/stdc++.h>
#define maxN 500005
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
        val = 0, lazy = -1;
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
        node[k] = Node(0, -1);
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    node[k].val = max(node[2 * k].val, node[2 * k + 1].val);
}

void down(int k, int l, int r)
{
    int v = node[k].lazy;
    if (v != -1)
    {
        int m = (l + r) / 2;
        node[2 * k].val += v;
        node[2 * k + 1].val += v;
        node[2 * k].lazy += v;
        node[2 * k + 1].lazy += v;
        node[k].lazy = -1;
    }
}

void updateIT(int k, int l, int r, int u, int v, int val)
{
    // (u v) l, r (u v)
    if (v < l || r < u)
        return;
    // u (l, r) v
    if (u <= l && r <= v)
    {
        node[k].val += val;
        node[k].lazy += val;
        return;
    }

    int m = (l + r) / 2;
    down(k, l, r);
    updateIT(2 * k, l, m, u, v, val);
    updateIT(2 * k + 1, m + 1, r, u, v, val);

    node[k].val = max(node[2 * k].val, node[2 * k + 1].val);
    node[k].lazy = -1;
}

int queryIT(int k, int l, int r, int u, int v)
{

    // (u v) l, r (u v)
    if (v < l || r < u)
        return -oo;
    // u (l, r) v
    if (u <= l && r <= v)
        return node[k].val;

    int m = (l + r) / 2;
    down(k, l, r);
    return max(queryIT(2 * k, l, m, u, v), queryIT(2 * k + 1, m + 1, r, u, v));
}

int main()
{
    cin >> n >> q;
    initIT(1, 1, n);
    while (q--)
    {
        int t, u, v, val;
        cin >> t >> u >> v;
        if (t == 0)
        {
            cin >> val;
            updateIT(1, 1, n, u, v, val);
        }
        else
        {
            cout << queryIT(1, 1, n, u, v) << endl;
        }
    }
}