#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[1007];
        cin >> n;
        int l = 1, r = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            r = max(r, a[i]);
        }

        int d = 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int s = 0;
            for (int i = 0; i < n; ++i)
            {
                s += (a[i] >= m);
            }
            if (s >= m)
            {
                ++l;
                d = max(d, m);
            }
            else
                --r;
        }
        cout << d << endl;
    }
}