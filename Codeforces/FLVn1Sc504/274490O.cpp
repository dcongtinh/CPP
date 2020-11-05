#include <bits/stdc++.h>
#define maxN 30005

using namespace std;

int n;
int a[maxN];
set<int> st[4 * maxN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        // Đoạn gồm 1 phần tử. Ta dễ dàng khởi tạo nút trên ST.
        st[id].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), inserter(st[id], st[id].end()));
}

set<int> get(int id, int l, int r, int u, int v)
{ // Trả lời truy vấn (x, y, k)
    if (v < l || r < u)
    {
        set<int> s;
        return s;
    }

    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    auto x = get(id * 2, l, mid, u, v);
    auto y = get(id * 2 + 1, mid + 1, r, u, v);
    set<int> s;
    // s.insert(y.begin(), y.end());
    merge(x.begin(), x.end(), y.begin(), y.end(), inserter(s, s.end()));
    return s;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        auto ans = get(1, 1, n, l, r);
        cout << ans.size() << endl;
    }
}