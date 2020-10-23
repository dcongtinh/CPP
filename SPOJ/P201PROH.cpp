#include <bits/stdc++.h>
#define ll long long
using namespace std;

string solve(ll a, ll b)
{
    if (a >= b)
        return "YES";
    if (a % 2 == 0 && 3 * a / 2 > a)
        return "YES";
    if (a % 2 == 1 && 3 * (a - 1) / 2 > a)
        return "YES";
    return "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}