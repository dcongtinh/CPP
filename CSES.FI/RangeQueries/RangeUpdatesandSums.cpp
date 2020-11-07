/*
Your task is to maintain an array of n values and efficiently process the following types of queries:
    1. Increase each value in range [a,b] by x.
    2. Set each value in range [a,b] to x.
    3. Calculate the sum of values in range [a,b].
*/
#include <bits/stdc++.h>
#define ll long long
#define maxN 200005

using namespace std;

int n, q;
int a[maxN];

struct node
{
    ll sum, inc;
    bool set;
};

node st[4 * maxN];

void initIT(int k, int l, int r)
{
    if (l == r)
    {
        st[k] = {a[l], 0, 0};
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    st[k].sum = st[2 * k].sum + st[2 * k + 1].sum;
}

void app(int k, ll x, bool is_set, int u, int v)
{
    if (is_set)
    {
        st[k].sum = 0;
        st[k].inc = 0;
        st[k].set = 1;
    }
    st[k].sum += x * (v - u + 1);
    st[k].inc += x;
}

void push_down(int k, int l, int m, int r)
{
    // Lazy Update
    app(2 * k, st[k].inc, st[k].set, l, m);
    app(2 * k + 1, st[k].inc, st[k].set, m + 1, r);

    // ll inc = st[k].inc;
    // bool is_set = st[k].set;

    // if (is_set)
    // {
    //     st[2 * k].sum = st[2 * k + 1].sum = 0;
    //     st[2 * k].inc = st[2 * k + 1].inc = 0;
    //     st[2 * k].set = st[2 * k + 1].set = 1;
    // }
    // st[2 * k].sum += st[k].inc * (m - l + 1);
    // st[2 * k + 1].sum += st[k].inc * (r - m);

    // st[2 * k].inc += st[k].inc;
    // st[2 * k + 1].inc += st[k].inc;

    // reset
    st[k].set = false;
    st[k].inc = 0;
}
void update(int k, int l, int r, int u, int v, ll x, bool is_set)
{
    if (v < l || r < u)
        return;
    if (u <= l && r <= v)
    {
        app(k, x, is_set, l, r);
        // if (is_set)
        // {
        //     st[k].sum = 0;
        //     st[k].inc = 0;
        //     st[k].set = 1;
        // }
        // st[k].sum += x * (r - l + 1);
        // st[k].inc += x;
        return;
    }
    int m = (l + r) / 2;
    push_down(k, l, m, r);
    update(2 * k, l, m, u, v, x, is_set);
    update(2 * k + 1, m + 1, r, u, v, x, is_set);
    st[k].sum = st[2 * k].sum + st[2 * k + 1].sum;
}

ll query(int k, int l, int r, int u, int v)
{
    // (u v) l r
    if (v < l || r < u)
        return 0LL;

    if (u <= l && v >= r)
        return st[k].sum;

    int m = (l + r) / 2;
    push_down(k, l, m, r);

    return query(2 * k, l, m, u, v) + query(2 * k + 1, m + 1, r, u, v);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    initIT(1, 1, n);
    while (q--)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t != 3)
        {
            int x;
            scanf("%d", &x);
            bool set_val = (t == 2);
            update(1, 1, n, a, b, x, set_val);
        }
        else
            printf("%lld\n", query(1, 1, n, a, b));
    }
    return 0;
}
