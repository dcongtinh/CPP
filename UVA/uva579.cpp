#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int h, m;
    int d[] = {0, 330, 300, 270, 240, 210, 180, 150, 120, 90, 60, 30, 0};
    while (scanf("%d:%d", &h, &m) && h != 0){
        float ans = d[h] + m*(6-0.5);
        while (ans > 180) ans = abs(ans-360);
        printf("%.3f\n", ans);
    }

    return 0;
}
