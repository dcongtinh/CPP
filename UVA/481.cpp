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

int n, lis[maxN], lis_id[maxN], trace[maxN], l=0, a[maxN];

void print_lis(int i){
    if (i == -1) return;
    print_lis(trace[i]);
    printf("%d\n", a[i]);
}
int main(){
    freopen("input.txt", "r", stdin);
    //freopen("input.out", "w", stdout);
    for (int i = 0; ;++i){
        if (scanf("%d", &a[i]) == EOF) break;
        int pos = lower_bound(lis, lis+l,a[i])-lis;
        lis[pos] = a[i];
        lis_id[pos] = i;
        trace[i] = ((pos > 0) ? lis_id[pos-1] : -1);
        if (pos == l) ++l;
    }
    printf("%d\n-\n", l);
    print_lis(lis_id[l-1]);
    return 0;
}

