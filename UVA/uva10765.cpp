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
#define vi vector<int>
#define ll long long
#define maxN 1005
#define oo 10000000007

using namespace std;

int n, m, low[maxN], num[maxN], d[maxN], parent[maxN], root, dfsCount=0, nChild=0;
vi ke[maxN];
bool isCut[maxN];
vector<ii> ans;

void CLEAR(){
    dfsCount=nChild=0;
    ms(low, 0);ms(num, 0);
    fto(i,0,n-1) ke[i].clear(), d[i]=1;
    root=0;ans.clear();
}

void dfs(int u){
    low[u]=num[u]=++dfsCount;
    int m=(int)ke[u].size();
    fto(i,0,m-1){
        int v=ke[u][i];
        if (!num[v]){
            if (u==root) ++nChild;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u], low[v]);
            if (low[v] >= num[u]) isCut[u]=true, ++d[u];
        } else if (parent[u] != v) low[u]=min(low[u], num[v]);
    }
}

bool cmp(ii a, ii b){
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi > b.fi;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    while (scanf("%d%d", &n, &m) && n && m){
        int u, v;
        CLEAR();
        while (scanf("%d%d",&u, &v) && u!=-1){
            ke[u].pb(v);
            ke[v].pb(u);
        }
        dfs(0);
        isCut[0]=(nChild > 1);

        if (!isCut[0])d[0]=1;
        fto(i,0,n-1) ans.pb(mp(d[i], i));
        sort(ans.begin(), ans.end(), cmp);
        fto(i,0,m-1) printf("%d %d\n", ans[i].se, ans[i].fi);
        printf("\n");
    }
    return 0;
}
