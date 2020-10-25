/*
    Keywords: Lyndon factorization, Duval Algo
*/
#include <bits/stdc++.h>

using namespace std;

/*
    Complexity: O(n)
*/
int min_cyclic_index(string s)
{
    s += s;
    int m = s.size();
    int f[m];
    for (int i = 0; i < m; ++i)
        f[i] = -1;
    int k = 0;
    for (int j = 1; j < m; ++j)
    {
        int sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1])
        {
            if (sj < s[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if (sj != s[k + i + 1])
        {
            if (sj < s[k])
                k = j;
            f[j - k] = -1;
        }
        else
            f[j - k] = i + 1;
    }
    return k;
}
/*
    Complexity: O(n)
*/
string min_cyclic_string(string s)
{
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}

vector<string> duval(string const &s)
{
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n)
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

int main()
{
    string s = "";
    cin >> s;
    int k = min_cyclic_index(s);
    cout << min_cyclic_index(s) << endl;
    cout << s.substr(k, s.size()) + s.substr(0, k);

    // cout << min_cyclic_string(s) << endl;

    // auto v = duval("amandamanda");
    // for (auto s : v)
    // {
    //     cout << s << endl;
    // }
}