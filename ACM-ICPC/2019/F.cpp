#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 1000000007;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            int j = n / i;
            ans = min(ans, 2 * i + 2 * j);
        }
    }
    cout << ans;
}