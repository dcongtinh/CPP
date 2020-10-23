#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll powLL(ll a, ll n) {
    if (n == 0) return 1LL;
    if (n == 1) return a;
    ll tmp = pow(a, n/2);
    if (n%2 == 0) return tmp*tmp;
    else return tmp*tmp*a;
}

int main()
{
    ll n;
    cin >> n;
    ll odd_sum = powLL((n + 1) / 2, 2);
    ll sum = n * (n + 1) / 2;
    ll even_sum = sum - odd_sum;
    cout << even_sum - odd_sum;
    cout << endl << powLL(1000, 2);
}