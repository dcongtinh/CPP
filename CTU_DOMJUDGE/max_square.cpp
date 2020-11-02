#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define maxN 2000

using namespace std;

int n, m, res = 0, a[maxN][maxN], l[maxN], r[maxN], h[maxN];

int main()
{
    // freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    fto(i, 1, n) fto(j, 1, m) scanf("%d", &a[i][j]);
    h[0] = h[m + 1] = -1;
    int ans = 0;
    fto(i, 1, n)
    {
        fto(j, 1, m) h[j] = (h[j] + 1) * a[i][j];
        fto(j, 1, m)
        {
            l[j] = j;
            while (h[j] <= h[l[j] - 1])
                l[j] = l[l[j] - 1];
        }
        fdto(j, m, 1)
        {
            r[j] = j;
            while (h[j] <= h[r[j] + 1])
                r[j] = r[r[j] + 1];
        }
        fto(j, 1, m)
        {
            int d = min(h[j], r[j] - l[j] + 1);
            ans = max(ans, d*d);
        }
    }
    printf("%d", ans);
    return 0;
}