#include <bits/stdc++.h>
#define maxC 1000000007

using namespace std;



int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int h, d;
    float u, f;
    while (scanf("%d%f%d%f", &h, &u, &d, &f) && h != 0){
        int ans = 0;
        bool ok = false;
        float dem = 0;
        f = float(f*u)/100;

        do{
            dem += u;
            ++ans;
            if (dem > h){
                printf("success on day %d\n", ans);
                ok = true;
                break;
            }
            dem -= d;
            u -= f;
            if (u < 0) u = 0;

        }while(dem >= 0);
        if (!ok) printf("failure on day %d\n", ans);

    }

    return 0;
}
