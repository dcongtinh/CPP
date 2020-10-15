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

int n, len, a[maxN], ans;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &len, &n);
        len *= 100;
        queue<int> l, r;
        fto(i,1,n){
            int x; string s;
            scanf("%d", &x);cin >> s;
            if (s == "left") l.push(x);
            else r.push(x);
        }
        int ans=0;
        while (!l.empty() || !r.empty()){
            int sum=0;
            while (!l.empty()){
                if (sum+l.front() > len) break;
                sum += l.front();
                l.pop();
            }
            ++ans;

            if (l.empty() && r.empty()) break;
            sum=0;
            while (!r.empty()){
                if (sum+r.front() > len) break;
                sum += r.front();
                r.pop();
            }
            ++ans;
            if (l.empty() && r.empty()) break;
        }
        printf("%d\n", ans);
        //return 0;
    }
    return 0;
}
