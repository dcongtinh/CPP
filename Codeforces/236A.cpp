#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    map<char, int> m;

    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        ++m[s[i]];
    if (m.size() % 2)
        return cout << "IGNORE HIM!", 0;
    return cout << "CHAT WITH HER!", 0;
}