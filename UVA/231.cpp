#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lld long long
#define maxN 1000005
#define oo 1000000007

using namespace std;

int n, lis[maxN], l=0, T = 0, a[maxN];

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);
    bool firstline=true;
    while (scanf("%d", &a[0]) && a[0]!=-1){
        int n=1;
        ++T;
        for (int i = 1; ;++i){
            if (scanf("%d", &a[i]) && a[i]== -1) break;
            ++n;
        }
        reverse(a,a+n);
        fto(i,0,n-1){
            int pos = lower_bound(lis, lis+l,a[i])-lis;
            lis[pos] = a[i];
            if (pos == l) ++l;
        }
        if (!firstline) printf("\n");
        else firstline=false;
        printf("Test #%d:\n", T);
        printf("  maximum possible interceptions: %d\n", l);

        l = 0;
    }
    return 0;
}

