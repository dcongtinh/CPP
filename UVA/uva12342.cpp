#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int a[] = {180000, 300000, 400000, 300000};
    int b[] = {0, 10, 15, 20, 25};

    int nT;
    scanf("%d", &nT);
    for (int iT = 1; iT <= nT; ++iT){
        int n, k = 0;
        double ans = 0;
        scanf("%d", &n);
        while (n >= a[k] && k < 4){
            ans += (double)ceil(a[k]*b[k]/100.0);
            n -= a[k];
            ++k;
        }

        if (n > 0) ans += (double)ceil(n/100.0*b[k]);
        if (ans < 2000 && ans != 0) ans = 2000;
        printf("Case %d: %.f\n", iT, ans);
    }

    return 0;
}





