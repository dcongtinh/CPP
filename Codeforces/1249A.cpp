#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[1000];
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        bool ok = true;
        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ok &= (abs(a[i] - a[j]) != 1);
            }
        }
        cout << 2 - ok << endl;
    }
    return 0;
}