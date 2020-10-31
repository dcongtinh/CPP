#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define ll long long
#define oo 1000000007
#define maxN 1000005

using namespace std;

int n, m;
vector<int> vc1, vc2, ans;
ll mod = 1000000003LL, hashT = 0LL;
ll hashS[maxN], pow26[maxN];
string s;

int getHash(int i, int j)
{
    /// M� hash x�u S[i..j]
    return (hashS[j] - hashS[i - 1] * pow26[j - i + 1] + mod * mod) % mod;
}

void buildHash()
{
    pow26[0] = 1;
    fto(i, 1, m) pow26[i] = (pow26[i - 1] * 26) % mod;

    ///T�m m� hash x�u S[1..i]
    fto(i, 1, m) hashS[i] = (hashS[i - 1] * 26 + s[i] - 'a') % mod;
}

bool check(int l)
{
    hashT = getHash(1, l);
    int i;
    for (i = l + 1; i <= m - l + 1; i += l)
    {
        if (getHash(i, i + l - 1) != hashT)
            return false;
    }
    // if (l == 3)
    //     cout << m << " " << l << endl;
    if (m % l != 0)
    {
        return getHash(1, m % l) == getHash(m - m % l + 1, m);
    }
    return true;
}

int compare(int idx, int i, int m)
{
    while (idx <= m)
    {
        if (s[idx] > s[i])
            return i;
        if (s[idx] < s[i])
            return idx;
    }
    return idx;
}

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

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    getline(cin, s);

    s = "";
    string tmp;
    while (s.size() < n)
    {
        getline(cin, tmp);
        s += tmp;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            vc1.push_back(s[i] - 'a' + 1);
        }
    }

    s = "";
    while (s.size() < n)
    {
        getline(cin, tmp);
        s += tmp;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            vc2.push_back(s[i] - 'a' + 1);
        }
    }

    for (int i = 0; i < vc1.size(); ++i)
    {
        if (vc2[i] - vc1[i] < 0)
            ans.push_back(vc2[i] + 26 - vc1[i]);
        else
            ans.push_back(vc2[i] - vc1[i]);
    }

    s = "";

    for (int i = 0; i < ans.size(); ++i)
    {
        char x = (char)('a' + ans[i] - 1);
        s += x;
    }
    s = '#' + s;
    m = s.length() - 1;
    buildHash();
    int ans = oo;
    for (int l = 1; l <= m; ++l)
    {
        if (check(l))
        {
            ans = l;
            break;
        }
    }
    string t = s.substr(1, ans);
    cout << min_cyclic_string(t);

    return 0;
}