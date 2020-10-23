#include <bits/stdc++.h>
#define ll long long
#define oo 1000000007

using namespace std;

int tich(int x){
    int t = 1;
    while (x) {
        t *= (x%10);
        x /= 10;
    }
    return t;
}

void solve(int n){
    for (int i = 1; i <= 999; ++i)
    {
        if (tich(i) == n)
        {
            cout << n << " " << i << endl;
            return;
        }
    }
    cout << n << " " << -1 << endl;
}
int main()
{
    int n;
    // cin >> n;
    for (int i = 1; i <= 100; ++i) solve(i);
}