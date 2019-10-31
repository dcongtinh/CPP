#include <bits/stdc++.h>
#define oo 1000000007
#define maxN 100005
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> sp;
    int a[maxN], b[maxN];
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i)
    {
        sp.insert({i, i});     //weight, i
        a[i] = b[i] = i;       //a[i] = weight, b[weight] = i
        ans.push_back({i, i}); //max, min
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        auto p = sp.lower_bound({a[x], x});
        auto p_prev = sp.lower_bound({a[x] - 1, b[a[x] - 1]});

        int p_dist = (*p).first;
        int p_post = (*p).second;
        cout << p_dist << " " << p_post << endl;
        int p_prev_dist = (*p_prev).first;
        int p_prev_post = (*p_prev).second;
        cout << p_prev_dist << " " << p_prev_post << endl;

        swap(a[p_dist], a[p_prev_dist]);
        // cout << a[p_dist] << " " << a[p_prev_dist] << endl;
        swap(b[p_post], b[p_prev_post]);
        // cout << b[p_post] << "  " << b[p_prev_post] << endl;
        // cout << a[p_dist] << " " << b[p_post] << endl;
        // cout << a[p_prev_dist] << " " << b[p_prev_post] << endl;
        sp.erase(p);
        sp.erase(p_prev);
        sp.insert({a[p_dist], b[p_post]});
        sp.insert({a[p_prev_dist], b[p_prev_post]});
        ans[x] = {min(ans[x].first, a[x]), max(ans[x].second, a[x])};
        cout << "---------------\n";
        break;
    }
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}