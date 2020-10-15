#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
string s;
int main(){
    freopen("input.txt", "r", stdin);
    while (getline(cin, s)){
        int m=s.length();
        fto(i,0,m-1) printf("%c", s[i]-7);
        printf("\n");
    }
    return 0;
}
