#include <bits/stdc++.h>

using namespace std;

bool visit[105][105], check;
char a[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, res, X, Y;

void loang(int u, int v){
    visit[u][v] = true;
    ++res;
    if (v == 1 && a[u][v] == a[X][Y] && a[u][n] == a[X][Y] && !visit[u][n]) loang(u, n);
    if (v == n && a[u][v] == a[X][Y] && a[u][1] == a[X][Y] && !visit[u][1]) loang(u, 1);

    if (a[u-1][v] == a[X][Y] && !visit[u-1][v]) loang(u-1, v);
    if (a[u+1][v] == a[X][Y] && !visit[u+1][v]) loang(u+1, v);
    if (a[u][v-1] == a[X][Y] && !visit[u][v-1]) loang(u, v-1);
    if (a[u][v+1] == a[X][Y] && !visit[u][v+1]) loang(u, v+1);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE


    while (scanf("%d%d", &m, &n) != EOF){

        memset(visit, true, sizeof(visit));

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                visit[i][j] = false;
                cin >> a[i][j];
            }
        }

        scanf("%d%d", &X, &Y);
        ++X; ++Y;

        loang(X, Y);
        int ans = 0;

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (!visit[i][j] && (a[i][j] == a[X][Y])){
                    res = 0;
                    loang(i, j);
                    ans = max(ans, res);
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
