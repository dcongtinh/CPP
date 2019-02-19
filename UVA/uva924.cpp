#include <bits/stdc++.h>

using namespace std;

int dem[10005], ngay[10005], a[10005];
vector<int> ke[10005];

bool bfs(int s){
    bool ans = false;
    queue<int> q;
    q.push(s);
    ngay[s] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (vector<int>::iterator it = ke[u].begin(); it != ke[u].end(); it++){
            int v = (*it);
            if (ngay[v] == -1){
                ngay[v] = ngay[u] + 1;
                ++dem[ngay[v]];
                q.push(v);
                ans = true;
            }
        }
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int E, T;
    scanf("%d", &E);

    for (int iE = 0; iE < E; ++iE){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);
            ke[iE].push_back(x);
        }
    }
    scanf("%d", &T);
    while (T--){
        int x;
        scanf("%d", &x);

        memset(ngay, -1, sizeof(ngay));
        memset(dem, 0, sizeof(dem));

        if (!bfs(x)){
            puts("0");
        } else {
            int M = 0, D = 0;
            for (int i = 1; i <= E; ++i){
                if (dem[i] > M){
                    M = dem[i];
                    D = i;
                }
            }

            printf("%d %d\n", M, D);
        }
    }
    return 0;
}
