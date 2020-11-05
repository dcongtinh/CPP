#include <bits/stdc++.h>
#define maxN 30005

using namespace std;

int n;
int a[maxN];
vector<int> st[4 * maxN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        // Đoạn gồm 1 phần tử. Ta dễ dàng khởi tạo nút trên ST.
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].resize(st[id * 2].size() + st[id * 2 + 1].size());
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), st[id].begin());
}

int get(int id, int l, int r, int u, int v, int k)
{ // Trả lời truy vấn (x, y, k)
    if (v < l || r < u)
        return 0;

    if (u <= l && r <= v)
    {
        // Đếm số phần tử > K bằng chặt nhị phân
        return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
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
        int l, r, k;
        cin >> l >> r >> k;
        cout << get(1, 1, n, l, r, k) << endl;
    }
}