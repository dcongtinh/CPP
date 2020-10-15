#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    m['h'] = 1;
    m['e'] = 1;
    m['l'] = 2;
    m['o'] = 1;
    string ans, res = "hello";
    int idx = 0;
    for (auto c : res)
    {
        if (m[c])
        {
            for (int i = idx; i < s.length(); ++i)
            {
                if (s[i] == c)
                {
                    --m[s[i]];
                    ans.push_back(s[i]);
                    idx = i + 1;
                    break;
                }
            }
        }
    }

    cout << (ans == "hello" ? "YES" : "NO");
}