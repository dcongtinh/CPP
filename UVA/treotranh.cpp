#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f;

bool check(){
    if (c + e <= a && max(d, f) <= b) return true;
    return false;
}

int main(){
    //freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &a, &b) != EOF){
        scanf("%d%d%d%d", &c, &d, &e, &f);
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if (e > f) swap(e, f);
        if (check()) puts("YES");
        else puts("NO");
    }

    return 0;
}
