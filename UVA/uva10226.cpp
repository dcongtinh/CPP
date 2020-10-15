#include <bits/stdc++.h>

using namespace std;



int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUEGE

    int T;
    scanf("%d", &T);
    string s;
    getline(cin, s);
    getline(cin, s);
    while (T--){
        map<string, int> a;
        string s;
        int sum = 0;
        while (getline(cin, s)){
            if (s.length() == 0) break;
            a[s] += 1;
            ++sum;
        }

        for (map<string, int>::iterator it = a.begin(); it != a.end(); it++){
            cout << it->first << " ";
            printf("%.4f\n", (float)(*it).second/sum*100.0);
        }
        if (T != 0) printf("\n");
    }
}
