#include <bits/stdc++.h>
#define maxN 200005

using namespace std;

int n, q;
long long f[maxN];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        f[i] = f[i - 1] + x;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
    }
}