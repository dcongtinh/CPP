#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        ans += (s[1] == '+' ? 1 : -1);
    }
    cout << ans;
}