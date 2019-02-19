#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int k;
    while (scanf("%d", &k) && k != 0){
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= k; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == n || y == m) puts("divisa");
            else if (x > n && y > m) puts("NE");
            else if (x > n && y < m) puts("SE");
            else if (x < n && y > m) puts("NO");
            else if (x < n && y < m) puts("SO");
        }
    }
    return 0;
}
