#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lld long long
#define maxN 105
#define oo 1000000007

using namespace std;

struct cube{
    int x, y, z;
    inline bool operator < (const cube &c) const{
        return ((x < c.x && y < c.y) || (x < c.y && y < c.x));
    }
};

int f[maxN];
cube c[maxN];

int dp(int k, int n){
    if (f[k] > 0) return f[k];
    int res = 0;
    fto(i,0,n){
        if (c[k] < c[i]){
            int tmp = dp(i,n);
            res = max(res, tmp);
        }
    }
    return (f[k] = res + c[k].z);
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);
    int n, T = 0;
    while (scanf("%d", &n) && n != 0){
        fto(i,0,n-1){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            c[3*i].x = x; c[3*i].y = y; c[3*i].z = z;
            c[3*i+1].x = y; c[3*i+1].y = z; c[3*i+1].z = x;
            c[3*i+2].x = z; c[3*i+2].y = x; c[3*i+2].z = y;
        }
        ++T;
        memset(f, 0, sizeof f);
        int ans=0;
        fto(i,0,3*n-1) ans=max(ans, dp(i,3*n-1));
        printf("Case %d: maximum height = %d\n", T, ans);
    }
    return 0;
}
