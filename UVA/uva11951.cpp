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
#define maxN 1005
#define oo 1000000007

using namespace std;

int n, m;
int k, f[maxN][maxN];

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    fto(iT,1,T){
        scanf("%d%d%d", &m, &n, &k);

        fto(i,1,m){
            fto(j,1,n){
                int x;
                scanf("%d", &x);
                f[i][j] = f[i-1][j] + x;
            }
        }
        int ans1=oo;
        int ans=-maxN*maxN;
        int p;
        fto(i1,1,m){
            fto(i2,i1,m){
                int vt=1, sum=0;
                fto(j,1,n){
                    sum += f[i2][j]-f[i1-1][j];
                    if (sum > k) while (sum > k) sum -= (f[i2][vt]-f[i1-1][vt]), ++vt;
                    p = (i2-i1+1)*(j-vt+1);
                    if (p >= ans){
                        if (p == ans) ans1=min(ans1, sum);
                        else ans1 = sum, ans=p;
                    }
                }
            }
        }
        printf("Case #%d: %d %lld\n", iT, ans, ans1);
    }
    return 0;
}
