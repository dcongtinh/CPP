#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define vi vector<int>
#define ms(a, x) memset(a, x, sizeof a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define maxN 1000005
#define oo 1000000007

using namespace std;

int n;
int h[maxN], l[maxN], r[maxN];

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE=
    while (scanf("%d", &n) && n)
    {
        fto(i, 1, n) scanf("%d", &h[i]);
        stack<int> stk;
        fto(i, 1, n)
        {
            while (!stk.empty() && h[stk.top()] >= h[i])
                stk.pop();
            if (stk.empty())
                l[i] = 0;
            else
                l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        fdto(i, n, 1)
        {
            while (!stk.empty() && h[stk.top()] >= h[i])
                stk.pop();
            if (stk.empty())
                r[i] = n + 1;
            else
                r[i] = stk.top();
            stk.push(i);
        }
        ll ans = 0LL;
        fto(i, 1, n)
        {
            ans = max(ans, (ll)(r[i] - l[i] - 1) * h[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
