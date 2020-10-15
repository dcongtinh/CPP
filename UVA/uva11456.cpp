#include <bits/stdc++.h>
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define ms(a, x) memset(a, x, sizeof a)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 2005
using namespace std;

int n, a[maxN], f[maxN], ff[maxN];

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        fto(i,1,n) scanf("%d", &a[i]);
        ms(f,0);ms(ff,0);
        fdto(i,n,1){
            f[i] = ff[i] = 1;
            fto(j,i+1,n) {
                if (a[i] > a[j]) f[i]=max(f[i], f[j]+1);
                if (a[i] < a[j]) ff[i]=max(ff[i], ff[j]+1);
            }
        }

        int ans=0;
        fto(i,1,n) ans=max(ans, f[i]+ff[i]-1);
        printf("%d\n", ans);
    }
    return 0;
}
