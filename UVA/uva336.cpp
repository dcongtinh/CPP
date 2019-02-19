#include <bits/stdc++.h>
#define maxN 55

using namespace std;

int n, s, t  =0, TTL, ttl[maxN], k;
map<int, int> m, rm;
vector<int> ke[maxN];

int bfs(int s){
    queue<int> q;
    q.push(s);
    ttl[s] = 0;
    int ans = 1;
    while (!q.empty()){
        int u = q.front(); q.pop();
         if (ttl[u] == TTL) return ans;
        for (int i = 0; i < ke[u].size(); ++i){
            int v = ke[u][i];
            if (ttl[v] == -1){
                q.push(v);
                ttl[v] = ttl[u] + 1;
                ++ans;
            }
        }
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d", &k) && k != 0){
        m.clear(); rm.clear();
        for (int i = 0; i <= maxN; ++i) ke[i].clear();
        n = 0;
        for (int i = 0; i < k; ++i){
            int u, v;
            scanf("%d%d", &u, &v);

            if (!m[u]){
                m[u] = ++n;
                rm[n] = u;
            }

             if (!m[v]){
                m[v] = ++n;
                rm[n] = v;
            }

            ke[m[u]].push_back(m[v]);
            ke[m[v]].push_back(m[u]);
        }

        while (scanf("%d%d", &s, &TTL) && (s != 0 || TTL != 0)){
            for (int i = 0; i <= n; ++i) ttl[i] = -1;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++t, m[s] ? n-bfs(m[s]) : n, s, TTL);
        }
    }

    return 0;
}
