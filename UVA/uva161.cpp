#include <bits/stdc++.h>

using namespace std;

int a[105][40000];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, k;

    while (1){
        k = 0;
        int x;
        while (scanf("%d", &x) && x != 0){
            ++k;
            for (int i = 0; i <= 18000; ++i){
                for (int j = 0; j < x-5; ++j) a[k][2*i*x + j] = 0;
                for (int j = x-5; j < x; ++j) a[k][2*i*x + j] = 1;
                for (int j = 0; j < x; ++j) a[k][(2*i + 1)*x + j] = 1;
            }
        }
        if (k == 0) break;
        bool ok1 = false, ok2 = true;
        for (int j = 0; j <= 18000; ++j){
            ok2 = true;
            for (int i = 1; i <= k; ++i){
                if (a[i][j] != 0){
                    ok1 = true;
                    ok2 = false;
                    break;
                }
            }
            if (ok1 && ok2){
                printf("%02d:%02d:%02d\n", j/3600, j%3600/60, j%60);
                ok2 = false;
                break;
            }
        }
        if (!ok1 && ok2) puts("...");
    }
}
