#include <bits/stdc++.h>
#define maxN 30005

using namespace std;

int n;
int st[4 * maxN], ans[200006];
vector<pair<int, int>> a;

struct Query
{
    int k;
    int l, r, id;
    Query(int _l, int _r, int _k, int _id)
    {
        l = _l;
        r = _r;
        k = _k;
        id = _id;
    }
};

// so sánh 2 truy vấn để dùng vào việc sort.
bool operator<(const Query &a, const Query &b)
{
    return a.k < b.k;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        // Nút id chỉ gồm 1 phần tử
        st[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int u)
{
    if (u < l || r < u)
    {
        // u nằm ngoài đoạn [l, r]
        return;
    }
    if (l == r)
    {
        st[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        // Đoạn [l, r] nằm ngoài đoạn [u, v]
        return 0;
    }
    if (u <= l && r <= v)
    {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v]
        return st[id];
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int Find(int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid].first >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<Query> queries; // các truy vấn
    // Đọc vào các truy vấn
    cin >> n;
    a.push_back({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int l, r, k;
        cin >> l >> r >> k;
        queries.push_back(Query(l, r, k, i));
    }
    // Sắp xếp các truy vấn
    sort(queries.begin(), queries.end());

    // Khởi tạo mảng id sao cho:
    // a[id[1]], a[id[2]], a[id[3]] là mảng a đã sắp xếp tăng dần.
    sort(a.begin(), a.end());

    // Khởi tạo Segment Tree
    build(1, 1, n);
    int prev = 1;
    for (Query q : queries)
    {
        int now = Find(prev, n, q.k + 1);
        for (int i = prev; i < now; i++)
            update(1, 1, n, a[i].second);
        prev = now;
        ans[q.id] = get(1, 1, n, q.l, q.r);
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << endl;
}