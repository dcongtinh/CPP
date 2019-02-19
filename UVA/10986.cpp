#include <bits/stdc++.h>
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lld long long
#define maxN 100005
#define oo 1000000007

using namespace std;

int n, m, p, s, t, d[maxN], trace[maxN];
vector<ii> ke[maxN];

void dijkstra(int s, int t){
    fto(i,0,n) d[i]=oo;
    d[s]=0;
    set<ii> q;
    q.insert(mp(d[s], s));
    while (!q.empty()){
        ii top = *(q.begin());
        q.erase(top);
        int u = top.se;
        int m = ke[u].size();
        fto(i,0,m-1){
            int v = ke[u][i].fi;
            int w = ke[u][i].se;
            if (d[v] > d[u] + w){
                q.erase(mp(d[v], v));
                d[v] = d[u] + w;
                q.insert(mp(d[v], v));
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int N;
    scanf("%d", &N);
    fto(T,1,N){
        scanf("%d%d%d%d", &n, &m, &s, &t);
        fto(i,0,n+1)ke[i].clear();
        fto(i,0,m-1){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            ke[u].pb(mp(v, w));
            ke[v].pb(mp(u, w));
        }
        dijkstra(s,t);
        printf("Case #%d: ", T);
        if (d[t]==oo) puts("unreachable");
        else printf("%d\n", d[t]);
    }
    return 0;
}

