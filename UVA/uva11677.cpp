#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int h1, m1, h2, m2;

    while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2)){

        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        if (h1 == h2){
            if (m1 <= m2) printf("%d\n", m2-m1);
            else printf("%d\n", 1440+ m2-m1);
        }
        else if (h1 < h2) printf("%d\n", abs((h1*60+m1) - (h2*60+m2)));

        else printf("%d\n", abs((h1*60+m1)-((h2+24)*60 + m2)));
    }

}
