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
#define maxN 105

using namespace std;

list<string> ls;
string s;
stringstream ss;
int num=0;
bool isNum, isWord;

void finishedNum(){
    //cout << num;
    list<string>::iterator it = ls.end();
    while (num--) --it;
    string t=(*it);
    cout << *it;
    ls.erase(it);
    ls.push_back(t);
    it=ls.end();
    isNum=false;
    num=0;
}

void finishedWord(){
    ls.push_back(ss.str());
    ss.str("");
    isWord=false;
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen(".out", "w", stdout);
    while (getline(cin, s) && s != "0"){
        int m=s.size();
        fto(i,0,m-1){
            if ('0' <= s[i] && s[i] <= '9'){
                num = 10*num + (s[i]-'0');
                isNum=true;
            } else if (isNum) finishedNum();

            if (isalpha(s[i])){
                ss << s[i];
                isWord=true;
            } else if (isWord) finishedWord();
            if (!isNum) cout << s[i];
        }
        if (isNum) finishedNum();
        if (isWord) finishedWord();
        cout << endl;
    }
    return 0;
}
