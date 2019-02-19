#include <bits/stdc++.h>

using namespace std;

unsigned int dao(unsigned int n){
    unsigned int  m = 0;
    while (n > 0){
        int  r = n%10;
        m = 10*m + r;
        n /= 10;
    }
    return m;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);
    while (nT--){
        unsigned int n;
        scanf("%u", &n);

        int ans = 0;
        while (n != dao(n)){
            ++ans;
            n += dao(n);
        }
        printf("%u %u\n", ans, n);
    }
}
