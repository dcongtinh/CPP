#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    while (scanf("%d", &n) && n != 0){
        int k = (int)sqrt(n);
        int m = n-k*k;
        if (m == 0){
            int x = 1, y = k;
            if (k%2==1)printf("%d %d\n", x, y);
            else printf("%d %d\n", y, x);
            continue;
        }


            int y = k, x = 1;
            ++y; --m;
            while (m > 0 && x < k+1 ) ++x, --m;
            while (m > 0) --y, --m;
        if (k%2)printf("%d %d\n", x, y);
        else printf("%d %d\n", y, x);
    }
    return 0;
}
