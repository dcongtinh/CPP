#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    while (T--){
        int n;
        scanf("%d", &n);
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n %= 100;
        n /= 10;
        printf("%d\n", abs(n));
    }
}
