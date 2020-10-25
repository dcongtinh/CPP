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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fastRead(s);
    fastRead(t);
    m = s.length() - 1, n = t.length() - 1;
    ///Tìm mã hash xâu T
    hashT = 0;
    fto(i, 1, n) hashT = (hashT * 26 + t[i] - 'a') % mod;

    pow26[0] = 1;
    fto(i, 1, m) pow26[i] = (pow26[i - 1] * 26) % mod;

    ///Tìm mã hash xâu S[1..i]
    fto(i, 1, m) hashS[i] = (hashS[i - 1] * 26 + s[i] - 'a') % mod;
    int ans = 0;
    fto(i, 1, m - n + 1)
    {
        if (hashT == getHash(i, i + n - 1))
            // printf("%d ", i);
            ++ans;
    }
    cout << ans;
    return 0;
}
