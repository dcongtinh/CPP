#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}