#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 1, ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
            ++cnt;
        else
        {
            if (cnt > 1)
                ans += cnt - 1;
            cnt = 1;
        }
    }
    if (cnt > 1)
        ans += cnt - 1;
    cout << ans;
}