#include <bits/stdc++.h>

using namespace std;

int  main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);

    while (nT--){
        unsigned int  x, y;
        cin >> x >> y;
        int a = -1;
        if ((x+y)%2 == 0) a = (x + y)/2;
        int b = x - a;
        if (b < 0 || a < 0) printf("impossible\n");
            else printf("%u %u\n", a, b);
    }

    return 0;
}
