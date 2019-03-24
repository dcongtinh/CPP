#include <bits/stdc++.h>

using namespace std;

int n, k, ans;

bool k_good(string s)
{
    map<int, int> m;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] - '0' <= k)
            ++m[s[i]];
    }
    return m.size() == k + 1;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        ans += (k_good(s));
    }
    cout << ans;
}