#include <bits/stdc++.h>

using namespace std;

int reverse(int n)
{
    int x = 0;
    vector<int> a;
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    sort(a.begin(), a.end());
    for (auto d : a)
        x = x * 10 + d;
    return x;
}

int main()
{
    int n, f[100];
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= 30; ++i)
    {
        f[i] = reverse(2 * f[i - 1]);
        // cout << i << " " << f[i] << endl;
    }
    if (n <= 29)
    {
        cout << f[n] << endl;
        return 0;
    }
    int trick[] = {244445, 48889, 77789, 155578, 111356, 122227};
    cout << trick[(n - 30) % 6];
}