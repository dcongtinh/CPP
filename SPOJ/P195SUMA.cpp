#include <bits/stdc++.h>
#define ll long long
#define oo 1000000007

using namespace std;

int main()
{
    int n, k, a[200007];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = *max_element(a, a + n), ans = oo;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int d = 0;
        for (int i = 0; i < n; ++i)
            d += (a[i] <= m);
        if (d >= k)
        {
            if (d == k)
                ans = min(ans, m);
            --r;
        }
        else
            ++l;
    }
    printf("%d", ans == oo ? -1 : ans);
}