#include <bits/stdc++.h>
#define oo 1000000007
#define maxN 500005
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[maxN], b[maxN];
    pair<int, int> ans[maxN];
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = {i, i};
        a[i] = b[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        int cur_dist = a[x];
        int cur_post = b[cur_dist];

        int prev_dist = max(a[cur_post] - 1, 1);
        int prev_post = b[prev_dist];

        swap(a[cur_post], a[prev_post]);
        swap(b[cur_dist], b[prev_dist]);
        auto p = ans[x];
        ans[x].first = min(p.first, a[cur_post]);
        ans[x].second = max(p.second, a[cur_post]);

        ans[prev_post].first = min(ans[prev_post].first, a[prev_post]);
        ans[prev_post].second = max(ans[prev_post].second, a[prev_post]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}