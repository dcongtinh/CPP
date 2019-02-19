#include <bits/stdc++.h>
#define maxN 10007

using namespace std;

vector<int> adj[maxN];
int dfs_num[maxN];
vector<int> t;

void toposort(int u){
    dfs_num[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if (!dfs_num[v]) toposort(v);
    }
    t.push_back(u);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE


    int n, m;

    while (scanf("%d%d", &n, &m) && n != 0){
        memset(dfs_num, 0, sizeof(dfs_num));
        t.clear();
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
        }
        for (int u = 1; u <= n; ++u) sort(adj[u].begin(), adj[u].end());

        for (int u = 1; u <= n; ++u){
            if (!dfs_num[u]){
                toposort(u);
            }
        }
        reverse(t.begin(), t.end());
        for (int i = 0; i < t.size(); ++i) cout << t[i] << " ";
        cout << endl;
    }

    return 0;
}

