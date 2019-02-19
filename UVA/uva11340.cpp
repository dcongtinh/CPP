#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);

    while (T--){
        int kVC, kLA, d[300];
        memset(d, 0, sizeof(d));

        unsigned long long ans = 0;

        scanf("%d", &kVC);
        getline(cin, s);
        for (int i = 0; i < kVC; ++i){
            int val; unsigned char c;
            scanf("%c %d", &c, &val);
            getline(cin, s);
            d[c] = val;
        }

        scanf("%d", &kLA);
        getline(cin, s);

        for (int i = 0; i < kLA; ++i){
            unsigned char c;
            while (scanf("%c", &c) && c != '\n') ans += d[c];
        }

        printf("%.2lf$\n", ans/100.0);
    }

    return 0;
}
