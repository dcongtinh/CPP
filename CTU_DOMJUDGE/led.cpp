#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string a[10] = {
        "01011111",
        "00000101",
        "01110110",
        "01110101",
        "00101101",
        "01111001",
        "01111011",
        "01000101",
        "01111111",
        "01111101"};
    while (T--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i)
        {
            cout << a[s[i] - '0'];
        }
        cout << endl;
    }
}