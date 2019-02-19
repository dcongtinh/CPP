#include <bits/stdc++.h>
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 105
using namespace std;

int a, b, c;
ll f[maxN][maxN][maxN];
int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &a, &b, &c);
        ll ans=INT_MIN;
        fto(i,1,a) fto(j,1,b) fto(k,1,c){
            ll x;
            cin >> x;
            f[i][j][k] = x + f[i-1][j][k] + f[i][j-1][k] + f[i][j][k-1];
            f[i][j][k] -= (f[i-1][j-1][k] + f[i][j-1][k-1] + f[i-1][j][k-1]);
            f[i][j][k] += f[i-1][j-1][k-1];
        }
        fto(i1,1,a) fto(j1,1,b) fto(k1,1,c)
            fto(i2,i1,a) fto(j2,j1,b) fto(k2,k1,c){
                ll sum=f[i2][j2][k2];
                sum -= (f[i1-1][j2][k2] + f[i2][j1-1][k2] + f[i2][j2][k1-1]);
                sum += (f[i1-1][j1-1][k2] + f[i2][j1-1][k1-1] + f[i1-1][j2][k1-1]);
                sum -= f[i1-1][j1-1][k1-1];
                ans=max(ans, sum);
            }
        cout << ans << endl;
        if (T) cout << endl;
    }
    return 0;
}
