#include <bits/stdc++.h>
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxN 300

using namespace std;

int n, k, a[maxN], p[maxN], len[maxN];
char ans[maxN], s[maxN];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.tt", "w", stdout);
    #endif // ONLINE_JUDGE
    while (scanf("%d", &n)&&n){
        fto(i,1,n) scanf("%d", &a[i]);
        fto(i,1,n){
            int t=i,d=1;
            while (a[t]!=i) t=a[t], ++d;
            len[i]=d;
            //cout << len[i] << " ";
        }
        while (scanf("%d", &k) && k){
            gets(s);
            int m=strlen(s);
            fto(i,m,n)s[i]=' ';
            fto(i,1,n)p[i]=i;
            fto(i,1,n){
                fto(j,1,k%len[i]) p[i]=a[p[i]];
            }
            fto(i,1,n) ans[p[i]]=s[i];
            fto(i,1,n) putchar(ans[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
