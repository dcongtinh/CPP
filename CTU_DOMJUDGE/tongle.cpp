#include <bits/stdc++.h>

using namespace std;

string solve(int odd, int even, int n)
{
    if (even == n || (odd == n && n % 2 == 0))
        return "NO";
    return "YES";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        int odd = 0, even = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            if (x % 2)
                ++odd;
            else
                ++even;
        }
        cout << solve(odd, even, n) << endl;
    }
}