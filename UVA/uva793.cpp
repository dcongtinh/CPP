#include <bits/stdc++.h>
#define maxN 100005

using namespace std;

int n, pset[maxN];

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
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    bool firstline = true;
    while (T--){
        if (!firstline) printf("\n");
        else firstline = false;
        scanf("%d", &n);
        int ans1 = 0, ans2 = 0, u, v;
        char p;
        initSet(n);
        string s;
        getline(cin, s);
        if (T != 0){
            while (scanf("%c", &p) && (p == 'q' || p == 'c')){
                scanf("%d%d", &u, &v);
                getline(cin, s);
                if (p == 'c') unionSet(u, v);
                else {
                    if (isSameSet(u, v)) ++ans1;
                    else ++ans2;
                }
            }
        } else {
            while (scanf("%c%d%d", &p, &u, &v) && getline(cin, s) && (p == 'q' || p == 'c')){

                if (p == 'c') unionSet(u, v);
                else {
                    if (isSameSet(u, v)) ++ans1;
                    else ++ans2;
                }
            }
        }
        printf("%d,%d\n", ans1, ans2);
    }

    return 0;
}
