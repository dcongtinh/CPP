#include <bits/stdc++.h>

using namespace std;

int d, m, pset[100005], ans[100005];
map<string, int> fr;
map<string, map<string, bool> > fre;
pair<string, string> b[100005];
string s1, s2;

void initSet(int n){
    for (int i = 1; i <= n; ++i) pset[i] = i, ans[i] = 1;
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
        scanf("%d", &m);
        int d = 0;
        fr.clear();
        for (int i = 1; i <= m; ++i){
            cin >> b[i].first >> b[i].second;
            if (fr[b[i].first] == 0) fr[b[i].first] = ++d;
            if (fr[b[i].second] == 0) fr[b[i].second] = ++d;

        }

        initSet(d);
        for (int i = 1; i <= m; ++i){
            s1 = b[i].first; s2 = b[i].second;
            unionSet(fr[s1], fr[s2]);

            int t = findSet(pset[fr[s1]]);
            int p = findSet(pset[fr[s2]]);
            if (s1 != s2 && !fre[s1][s2]) ++ans[t];
            //printf("%d\n", ans[t]);
            fre[s1][s2] = true;
        }
    }

    return 0;
}
