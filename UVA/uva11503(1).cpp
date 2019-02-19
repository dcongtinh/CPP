#include <bits/stdc++.h>

using namespace std;

int d, m, pset[100005], ans[100005];
map<string, int> fr;
map<string, map<string, bool> > fre;
pair<string, string> b[100005];
string s1, s2;

void initSet(){
    for (int i = 1; i <= 100005; ++i) pset[i] = i, ans[i] = 1;
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
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    while (T--){
        initSet();
        scanf("%d", &m);
        int d = 0;
        fr.clear();
        for (int i = 1; i <= m; ++i){
            cin >> s1 >> s2;
            if (fr[s1] == 0)fr[s1] = ++d;
            if (fr[s2] == 0)fr[s2] = ++d;

            int u = findSet(fr[s1]);
            int v = findSet(fr[s2]);
            if (u != v){
                pset[v] = u;
                ans[u] += ans[v];
            }
            printf("%d\n", ans[u]);
        }
    }

    return 0;
}
