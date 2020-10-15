#include <bits/stdc++.h>

using namespace std;

int n, m, pset[50005], b[50005];

void initSet(int n){
    for (int i = 1; i <= n; ++i) pset[i] = i;
}

int findSet(int u){
    return ((u == pset[u]) ? (u) : (pset[u] = findSet(pset[u])));
}

void unionSet(int u, int v){
    pset[findSet(u)] = findSet(v);
}

bool isSameSet(int u, int v){
    return (findSet(u) == findSet(v));
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T = 0;
    while (scanf("%d%d", &n, &m) && n != 0){
        ++T;
        initSet(n);

        for (int i = 0; i < m; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            unionSet(u, v);
        }
        int ans = 1;

        for (int i = 1; i <= n; ++i) b[i] = findSet(pset[i]);
        sort(b+1, b+n+1);

        for (int i = 2; i <= n; ++i){
            if (b[i-1] != b[i]) ++ans;
        }
        printf("Case %d: %d\n", T, ans);
    }

    return 0;
}
