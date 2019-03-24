#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length() < 7)
        return cout << "NO", 0;
    for (int i = 0; i <= s.length() - 7; ++i)
    {
        string substr = s.substr(i, 7);
        if (substr == "0000000" || substr == "1111111")
            return cout << "YES", 0;
    }
    return cout << "NO", 0;
}