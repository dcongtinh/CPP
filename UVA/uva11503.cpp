#include <bits/stdc++.h>

using namespace std;

int pset[100005];

int findSet(int u){
    if (pset[u] < 0) return u;
    return pset[u] = findSet(pset[u]);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);
    while (nT--){
        int k, id = 0;
        scanf("%d", &k);
        map<string, int> m;
        memset(pset, -1, sizeof(pset));
        for (int i = 0; i < k; ++i){
            string s1, s2;
            cin >> s1 >> s2;
            if (!m[s1]) m[s1] = ++id;
            if (!m[s2]) m[s2] = ++id;

            int p = findSet(m[s1]);
            int q = findSet(m[s2]);

            if (p == q){
                cout << -pset[p] << endl;
                continue;
            }

            if (pset[p] < pset[q]){
                pset[p] += pset[q];
                pset[q] = p;
                cout << -pset[p] << endl;
            } else {
                pset[q] += pset[p];
                pset[p] = q;
                cout << -pset[q] << endl;
            }
        }
    }
}
