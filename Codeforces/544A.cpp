#include <bits/stdc++.h>

using namespace std;
int k;
string s;
bool vis[300];
vector<int> pos;

int main()
{

    cin >> k >> s;
    for (int i = 0; i < s.length(); ++i)
        if (!vis[s[i]])
        {
            vis[s[i]] = true;
            pos.push_back(i + 1);
        }
    if (k > pos.size())
        return cout << "NO", 0;
    pos.push_back(s.length() + 1);
    auto it = pos.begin();
    auto it1 = it;
    ++it1;
    vector<string> v;
    int d = 0;
    for (; it1 != pos.end(); ++it1)
    {
        ++d;
        string str = "";
        if (d == k)
        {
            for (int i = (*it) - 1; i < s.length(); ++i)
                str += s[i];
            v.push_back(str);
            break;
        }
        for (int i = (*it) - 1; i < (*it1) - 1; ++i)
            str += s[i];
        v.push_back(str);
        it = it1;
    }
    cout << "YES" << endl;
    for (auto it : v)
        cout << it << endl;
}