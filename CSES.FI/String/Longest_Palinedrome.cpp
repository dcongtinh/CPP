#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 1000005

using namespace std;

int n, m;
ll mod = 1000000003LL, hashT = 0LL;
;
ll hashS[maxN], pow26[maxN];
string s, t;

void fastRead(string &s)
{
    char tmp[maxN];
    scanf("%s", tmp);

    s.assign(tmp);
    s = '#' + s;

    return;
}

int getHash(int i, int j)
{
    /// Mã hash xâu S[i..j]
    return (hashS[j] - hashS[i - 1] * pow26[j - i + 1] + mod * mod) % mod;
}

bool check(int l)
{
    // for (int i = 1; i <= m - l + 1; ++i)
    // {
    //     if
    // }
}

int main()
{
    fastRead(s);
    m = s.length() - 1;

    pow26[0] = 1;
    fto(i, 1, m) pow26[i] = (pow26[i - 1] * 26) % mod;

    ///Tìm mã hash xâu S[1..i]
    fto(i, 1, m) hashS[i] = (hashS[i - 1] * 26 + s[i] - 'a') % mod;
    int l = 1, r = m;
    int ans = 0;
    while (l <= r)
    {
        int len = (l + r) / 2;
        if (check(len))
        {
            ans = len;
            l = len + 1;
        }
        else
            r = len - 1;
    }
    return 0;
}
