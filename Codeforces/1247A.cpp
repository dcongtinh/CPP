#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 9 && b == 1)
        return cout << 9 << " " << 10, 0;
    if (abs(a - b) > 1 || a > b)
        return cout << -1, 0;

    if (b - a == 1)
        return cout << a << " " << b, 0;

    cout << a * 10 << " " << b * 10 + 1;
    return 0;
}