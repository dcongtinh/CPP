#include <bits/stdc++.h>

using namespace std;

string s;
vector<char> a;

bool check(vector<char> a){
    int m = a.size();
    for (int l = 0, r = m-1; l <= r; ++l, --r)
        if (a[l] != a[r]) return false;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    while (1){
        getline(cin, s);
        if (s == "DONE") break;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] >= 'A' && s[i] <= 'Z') a.push_back(s[i]);
            if (s[i] >= 'a' && s[i] <= 'z'){
                s[i] = toupper(s[i]);
                a.push_back(s[i]);
            }
        }
        if (check(a)) puts("Don't you won be eaten!");
        else puts("Uh oh..");
    }
}
