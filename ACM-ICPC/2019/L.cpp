#include <bits/stdc++.h>
#define oo 1000000007

using namespace std;

void find()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > c)
        swap(a, c);
    // int ans = max(a, max(b, c));
    int avg = (ceil)((a + b + c) / 3.0);
    int _a = max(a - avg, 0);
    int _b = max(b - avg, 0);
    int _c = max(c - avg, 0);
    // if (b > c)
    // {
    //     int m = (b - avg) / 2;
    //     a += m + m % 2;
    //     c += m;
    //     return max(a, max(b, c));
    // } else {
    //     for (int i = c; i >= avg; --i){

    //     }
    // }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        find();
    }
}