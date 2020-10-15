#include <bits/stdc++.h>

using namespace std;

int a[10], x, y, k;
bool c[10], dc[10], dp[10];

void dathau(int i){
    if (i > 8){
      //  if (a[x] == y){
            for(int j = 1; j < 9; ++j) printf("%d ", a[j]);
            printf("\n");
            return;
       // }
    }
    cout << i ;
    for (int j = 1; j < 9; ++j){
        if (c[j] && dc[i - j + 7] && dp[i + j -2]){
            c[j] = false;
            dc[i - j + 7] = false;
            dp[i + j - 2] = false;
            a[i] = j;
            dathau(i +1);
            c[j] = true;
            dc[i - j + 7] = true;
            dp[i + j - 2] = true;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8");
    printf("\n");
    printf("\n");

    int nT;
    scanf("%d", &nT);

    while (nT--){
        k = 0;
        scanf("%d%d", &x, &y);
        memset(c, true, sizeof(c));
        memset(dc, true, sizeof(dc));
        memset(dp, true, sizeof(dp));
        dathau(1);
        printf("\n");
    }

    return 0;
}
