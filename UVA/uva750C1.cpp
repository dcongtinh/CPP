#include <bits/stdc++.h>

using namespace std;

int a[10], dc[15], dp[15], x, y;

bool check(){
    memset(dc, false, sizeof(dc));
    memset(dp, false, sizeof(dp));
    //dc[x-y+7] = true; dp[x+y-2] = true;
    for(int i = 1; i < 9; ++i){
        if (dc[i - a[i] + 7] || dp[i + a[i] - 2]) return false;
        else {
                dc[i - a[i] + 7] = true;
                dp[i + a[i] - 2] = true;
        }
    }
    if (a[y] != x) return false;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);
    while (nT--){
        int k = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        scanf("%d%d", &x, &y);

        for(int i = 1; i < 9; ++i) a[i] = i;
        do {
           if (check()){
                ++k;
                if (k <= 9) printf(" %d      ", k);
                else printf("%d      ", k);
                for(int i = 1; i < 9; ++i) printf("%d ", a[i]);
                printf("\n");
           }
        } while (next_permutation(a+1, a+9));
        if (nT != 0) printf("\n");
    }
}
