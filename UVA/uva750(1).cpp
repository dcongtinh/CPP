#include <bits/stdc++.h>

using namespace std;

int a[10], dc[15], dp[15], x, y, k;
bool d[10];

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
    if (a[x] != y) return false;
    return true;
}


void hoanvi(int i){
    if (i > 8){
        if (check()){
                printf(" %d      ", ++k);
                for(int i = 1; i < 9; ++i) printf("%d ", a[i]);
                printf("\n");
           };
        return;
    }
    for (int j = 1; j < 9; ++j){
            if (!d[j]){
            a[i] = j;
            d[j] = true;
            hoanvi(i+1);
            d[j] = false;
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
        hoanvi(1);
        printf("\n");
    }
}
