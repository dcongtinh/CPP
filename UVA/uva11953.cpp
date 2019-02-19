#include <bits/stdc++.h>

using namespace std;

bool visit[105][105], check;
char a[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void loang(int u, int v){
    visit[u][v] = true;

    if (a[u][v] == 'x') check = true;

    if ((a[u-1][v] == 'x' || a[u-1][v] == '@')&& !visit[u-1][v]) loang(u-1, v);
    if ((a[u+1][v] == 'x' || a[u+1][v] == '@')&& !visit[u+1][v]) loang(u+1, v);
    if ((a[u][v-1] == 'x' || a[u][v-1] == '@')&& !visit[u][v-1]) loang(u, v-1);
    if ((a[u][v+1] == 'x' || a[u][v+1] == '@')&& !visit[u][v+1]) loang(u, v+1);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);
    for (int iT = 1; iT <= nT; ++iT){
        int n;
        scanf("%d", &n);
        memset(visit, true, sizeof(visit));

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                visit[i][j] = false;
                cin >> a[i][j];
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (!visit[i][j] && (a[i][j] == 'x' || a[i][j] == '@')){
                    check = false;
                    loang(i, j);
                    if (check) ++ans;
                }
            }
        }

        printf("Case %d: %d\n", iT, ans);
    }
    return 0;
}
