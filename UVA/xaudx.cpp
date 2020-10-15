#include <bits/stdc++.h>

using namespace std;

char s[100005];
int  k;
d[100005];

bool check(int l, int r){

}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        int m = strlen(s);
        d[0]=s[0];
        for (int i = 1; i < m; ++i){
            d[i] = d[i-1] + s[i];
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i){
            int l, r;
            scanf("%d%d", &l, &r);
            if (check(l, r)) puts("1");
            else puts("-1");
        }
    }
    return 0;
}
