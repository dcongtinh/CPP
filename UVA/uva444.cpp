#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x);i<=(y);++i)
#define fdto(i,x,y) for(int i=(x);i>=(y);--i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end();++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend();++rit)
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ii pair<int, int>
#define vi vector<int>
#define ms(a, x) memset(a, x, sizeof a)
#define ll long long
#define ull unsigned long long
#define oo 1000000007
#define maxN 1005

using namespace std;

string s, ans;

string toStr(int x){
   stringstream ss;
   ss << x;
   return ss.str();
}

int main(){
    freopen("input.txt", "r", stdin);
    while (getline(cin, s)){
        int m=s.length();
        int i=0;
        ans="";
        while (i < m){
            if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') ||  s[i] < '0' || s[i] > '9'){
                ans+=toStr(s[i]);
                ++i;
            } else {
                char c=(s[i+1]-'0')*10 + s[i]-'0';
                if (c <= 31) {
                    c+=(s[i+2]-'0')*100;
                    i+=3;
                } else i+=2;
                if (c==32) ans+=" ";else ans+=c;
            }

        }

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        //getline(cin, s);
        //return 0;
    }
    return 0;
}
