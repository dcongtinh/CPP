#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    int t, F[1007];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 1000; ++i)
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }
}