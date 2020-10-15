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

int k, G, B;

bool cmp(int u, int v){
    return (u > v);
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &k, &G, &B);
        multiset<int> SG, SB;

        fto(i,1,G){
            int x;
            scanf("%d", &x);
            SG.insert(x);
        }
        fto(i,1,B){
            int x;
            scanf("%d", &x);
            SB.insert(x);
        }

        while (!SG.empty() && !SB.empty()){
            int n = min(k, (int)min(SG.size(), SB.size()));
            vector<int> VG, VB;
            fto(i,1,n){
                multiset<int>::iterator it1, it2;
                it1 = SG.end();
                --it1;
                it2 = SB.end();
                --it2;
                VG.pb(*it1);
                VB.pb(*it2);
                SG.erase(it1);
                SB.erase(it2);
            }
            fto(i,0,n-1){
                if (VG[i] > VB[i]) SG.insert(VG[i]-VB[i]);
                else if (VB[i] > VG[i]) SB.insert(VB[i]-VG[i]);
            }
        }
        if (SB.empty() && SG.empty()) puts("green and blue died");
        else {
            if (SB.empty()){
                puts("green wins");
                forrit(rit, SG) cout << *rit << endl;
            }
            if (SG.empty()){
                puts("blue wins");
                forrit(rit, SB) cout << *rit << endl;
            }
        }
        if (T) printf("\n");
    }
    return 0;
}
