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
#define lld long long
#define maxN 100005
#define oo 1000000007

using namespace std;

int n, t, m, a[maxN];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &t, &m);
        fto(i,1,m) scanf("%d", &a[i]);
        int time = t, i=1, ans=0;
        while (i <= m){
            fdto(j,i+n-1,i){
                if (a[j] <= time+t && j<=m){
                    i=j+1;
                    if (a[j]==time) time+=2*t;
                    else time+=(time+t-a[j]+2*t);
                    ++ans;
                    //cout << time << endl;
                    //return 0;
                    break;
                }
            }
        }
        printf("%d %d\n", time, ans);
        //return 0;
    }
    return 0;
}
