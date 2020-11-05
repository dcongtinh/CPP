#include <bits/stdc++.h>
#define maxN 30005

using namespace std;

struct node
{
    int val, id;
};

struct query
{
    int k, id, l, r;
};
int a[maxN], n;
int f[maxN];
int s[maxN];
int ans[200005];
node A[maxN];
query Q[200005];

inline bool cmp(const node &a, const node &b) { return a.val > b.val; }
inline bool cmp1(const query &a, const query &b) { return a.k > b.k; }

inline int count(int x)
{
    int res = 0;
    while (x)
    {
        res += a[x], x -= x & -x;
    }
    return res;
}

inline void update(int x, const int inc)
{
    while (x <= n)
    {
        a[x] += inc;
        x += x & -x;
    }
}

int main()
{
    int q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        A[i].val = x;
        A[i].id = i;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        Q[i].l = l;
        Q[i].r = r;
        Q[i].k = k;
        Q[i].id = i;
        ans[i] = r - l + 1;
    }
    sort(A + 1, A + n + 1, cmp);
    sort(Q + 1, Q + q + 1, cmp1);
    int st = 1;
    for (int i = 1; i <= q && st <= n;)
    {
        if (st <= n && A[st].val > Q[i].k)
        {
            update(A[st].id, 1);
            ++st;
        }
        else
        {
            ans[Q[i].id] = count(Q[i].r) - count(Q[i].l - 1);
            ++i;
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    // getch();
}