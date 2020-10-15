#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define ms(a, x) memset(a, x, sizeof a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lld long long
#define maxN 105
#define oo 1000000007

using namespace std;

int n,m;
vector<int> a;

bool cmp(int u, int v){
    return (u > v);
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);

    while (scanf("%d", &n) && n){
        multiset<int> ms;
        lld ans=0LL;
        fto(i,0,n-1){
            int k;
            scanf("%d", &k);
            fto(j,1,k){
                int x;
                scanf("%d", &x);
                ms.insert(x);
            }
            /*multiset<int>::iterator it1, it2;
            it1 = ms.begin();
            it2 = ms.rbegin();
            --it2;
            ans += (*it2-*it1);
            ms.erase(it1);
            ms.erase(it2);*/
            ans += *(ms.rbegin())-*
        }
        cout << ans << endl;
    }
    return 0;
}
