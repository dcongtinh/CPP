#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int d[1005][1005], a[1005][1005];

void bfs(int u, int v){
    queue<pair<int, int> > q;
    q.push(make_pair(u, v));

    while (!q.empty()){
        pair<int, int> t = q.front();
        int x = t.first;
        int y = t.second;
        q.pop();
        for (int k = 0; k < 4; ++k){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (!d[xx][yy] && a[xx][yy] == 0){
                d[xx][yy] = d[x][y] + 1;
                q.push(make_pair(xx, yy));
            }
        }

    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int m, n, rows;
    while (scanf("%d%d", &m, &n) && m != 0){
        memset(a, -1, sizeof(a));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= m;++i){
            for (int j = 1; j <= n; ++j) a[i][j] = 0;
        }
        scanf("%d", &rows);
        for (int i = 0; i < rows; ++i){
            int r, c;
            scanf("%d%d", &r, &c);
            ++r;
            for (int j = 0; j < c; ++j){
                int x;
                scanf("%d", &x);
                ++x;
                a[r][x] = 1;
            }
        }
        int x, y,s, t;
        scanf("%d%d", &x, &y);
        ++x; ++y;
        bfs(x, y);
        scanf("%d%d", &s, &t);
        printf("%d\n", d[++s][++t]);
    }

    return 0;
}
