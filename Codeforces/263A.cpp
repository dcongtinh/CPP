#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    int a[6][6];
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                r = i;
                c = j;
            }
        }
    }
    cout << abs(r - 3) + abs(c - 3);
}