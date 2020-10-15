#include <bits/stdc++.h>
#define maxC 1000000007

using namespace std;

int n, b, h, w, p;

bool check(int p, int w){
    bool ok1 = false;

    for (int j = 1; j <= w; ++j){
        int a;
        scanf("%d", &a);
        if (a >= n) ok1 = true;
    }
    if (n*p > b) return false;
    if (ok1) return true;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE


    while (scanf("%d", &n) != EOF){

        scanf("%d%d%d", &b, &h, &w);

        int ans = maxC;
        for (int i = 1; i <= h; ++i){
            scanf("%d", &p);
            if (check(p, w)) ans = min(ans, p*n);
        }

        if (ans == maxC) puts("stay home");
        else printf("%d\n", ans);
    }


    return 0;
}
