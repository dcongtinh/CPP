#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ms(a, x) memset(a, x, sizeof a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define maxN 1005
#define oo 10000000007

using namespace std;

int n, g, T, p[maxN], w[maxN], ans=0, f[maxN][maxN];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> T;
    while (T--){
        cin >> n;
        fto(i,1,n) cin >> p[i] >> w[i];
        cin >> g;
        ans=0;
        fto(i,1,g){
            int m;
            cin >> m;
            ms(f, 0);
            fto(i,1,n){
                fto(j,0,m){
                    f[i][j]=f[i-1][j];
                    if (j >= w[i]) f[i][j]=max(f[i][j], f[i-1][j-w[i]]+p[i]);
                }
            }
            ans+=f[n][m];
        }
        cout << ans << endl;
    }

    return 0;
}
