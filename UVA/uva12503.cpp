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
        string s;
        vector<string> a;
        int ans = 0;

        for (int i = 0; i < n; ++i){
            cin >> s;
            if (s == "LEFT"){
                --ans;
                a.push_back("LEFT");
            }

            //return 0;
            if (s == "RIGHT"){
                ++ans;
                a.push_back("RIGHT");
            }

            if (s == "SAME"){
                string s1;
                int d;
                cin >> s1 >> d;
                getline(cin, s1);
                if (a[d-1] == "LEFT"){
                    --ans;
                    a.push_back("LEFT");
                }
                if (a[d-1] == "RIGHT"){
                    ++ans;
                    a.push_back("RIGHT");
                }
            }
        }

        printf("%d\n", ans);
    }
}
