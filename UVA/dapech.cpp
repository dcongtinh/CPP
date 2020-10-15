#include <bits/stdc++.h>

using namespace std;

int b[100005];

bool cmp(int a, int b){
    return (a > b);
}

int main(){
    //freopen("input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    while (T--){
        int n, m, k;
        map<int, int> a;
        scanf("%d%d%d", &n, &m, &k);

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                int x;
                scanf("%d", &x);
                ++a[x];
            }
        }
        int d = 0, ans = 0;

        for (map<int, int>::iterator it = a.begin(); it != a.end(); it++) b[d++] = it->second;

        sort(b, b+d, cmp);
        for (int i = 0; i < k; ++i) ans += b[i];
        printf("%d\n", ans);
    }
    return 0;
}
