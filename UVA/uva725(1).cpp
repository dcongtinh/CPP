#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <cfloat>
#define fo(s) freopen(s, "r", stdin);
#define pb push_back
#define mp make_pair
#define fto(i, x, y) for(int i = x; i <= y; ++i)
#define ms(a, x) memset(a, x, sizeof(a))
#define maxN 20005

using namespace std;

int n, a[10];
bool d[10], found;

void solve(int i){
    if (i > 9){
        int tu = 10000*a[0] + 1000*a[1] + 100*a[2] + 10*a[3] + a[4];
        int mau = 10000*a[5] + 1000*a[6] + 100*a[7] + 10*a[8] + a[9];
        if (tu == mau*n){
            found = true;
            fto(j, 0, 9){
                if (j == 5) printf(" / ");
                printf("%d", a[j]);
            }
            printf(" = %d\n", n);
        }
        return;
    }

    fto(j, 0, 9){
        if (d[j]){
            a[i] = j;
            d[j] = false;
            solve(i+1);
            d[j] = true;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
       fo("input.txt");
    #endif // ONLINE_JUDGE

    ms(d, true);
    while(1){
        scanf("%d", &n);
        if (n == 0) break;
        found = false;
        solve(0);
        if (!found) printf("There are no solutions for %d.\n", n);
        printf("\n");
    }

    return 0;
}


