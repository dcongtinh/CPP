#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    //getline(cin, s);
    for (int iT = 1; iT <= T; ++iT){
        int ans = 0;
        pair<string, int> a[20];

        for (int i = 0; i < 10; ++i){

            int d;
            cin >> s >> d;
            ans = max(ans, d);
            a[i].first = s;
            a[i].second = d;
        }
        printf("Case #%d:\n", iT);
        for (int i =0; i < 10; ++i){
            if (a[i].second == ans) cout << a[i].first << endl;
        }

    }
}

