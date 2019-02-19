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

int a[maxN], b[maxN], f[maxN][maxN];

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);
    int n, x;
    scanf("%d",&n);

    fto(i,1,n) scanf("%d", &x), a[x]=i;

    while (scanf("%d", &x) != EOF){
        b[x]=1;
        fto(i,2,n) scanf("%d", &x), b[x]=i;
        fto(i,1,n){
            fto(j,1,n){
                if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j]= max(f[i-1][j], f[i][j-1]);
            }
        }
        printf("%d\n", f[n][n]);
    }

    return 0;
}

