#include <bits/stdc++.h>

using namespace std;

map<string, int> b;
int a[105][105], deg[105];
map<int, string> rb;
string s;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, T = 0;
    while (scanf("%d", &n) != EOF){
        printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
        memset(a, 0, sizeof(a));
        memset(deg, 0, sizeof(deg));

        for (int i = 1; i <= n; ++i){
            cin >> s;
            b[s] = i;
            rb[i] = s;
        }

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i){
            string s1, s2;
            cin >> s1 >> s2;
            int u = b[s1], v = b[s2];
            if (a[u][v] == 0){
                a[u][v] = 1;
                ++deg[v];
            }
        }

        bool stop = false;

        while (!stop){
            stop = true;
            for (int u = 1; u <= n; ++u){
                if (deg[u] == 0){
                    --deg[u];
                    cout << " " << rb[u];
                    for (int v = 1; v <= n; ++v){
                        if (a[u][v] == 1){
                            --deg[v];
                        }
                    }
                    stop = false;
                    break;
                }
            }
        }
        printf(".\n\n");
    }
}
