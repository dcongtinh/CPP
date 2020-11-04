#include <bits/stdc++.h>
#define maxN 1000007
#define F first
#define S second

using namespace std;

string s;
struct Node
{
    int optimal;
    int open;
    int close;
    Node()
    {
        optimal = open = close = 0;
    }
    Node(int opt, int o, int c)
    { // Khởi tạo struct Node
        optimal = opt;
        open = o;
        close = c;
    }
    void print()
    {
        cout << optimal << " " << open << " " << close << endl;
    }
};

Node operator+(Node const &left, Node const &right)
{
    Node res;
    // min(số dấu "(" thừa ra ở cây con trái, và số dấu ")" thừa ra ở cây con phải)
    int tmp = min(left.open, right.close);

    // Để xây dựng kết quả tối ưu ở nút id, ta nối dãy ngoặc tối ưu ở 2 con, rồi thêm
    // min(số "(" thừa ra ở con trái, số ")" thừa ra ở con phải).
    res.optimal = left.optimal + right.optimal + tmp;

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

Node node[maxN * 4];

void initIT(int k, int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(')
            node[k] = Node(0, 1, 0);
        else
            node[k] = Node(0, 0, 1);
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    node[k] = node[2 * k] + node[2 * k + 1];
}

Node queryIT(int k, int l, int r, int i, int j)
{
    // (i, j) l r (i, j)
    if (j < l || i > r)
    {
        return Node(0, 0, 0);
    }
    // i (l r) j
    if (i <= l && r <= j)
    {
        return node[k];
    }
    int m = (l + r) / 2;
    return queryIT(k * 2, l, m, i, j) + queryIT(k * 2 + 1, m + 1, r, i, j);
}

int main()
{
    int m, n;
    cin >> s;
    s = '#' + s;
    m = s.length() - 1;
    initIT(1, 1, m);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        Node res = queryIT(1, 1, m, l, r);
        cout << res.optimal * 2 << endl;
    }
}