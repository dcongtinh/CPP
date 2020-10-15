#include <bits/stdc++.h>

using namespace std;

bool isLeap(int y){
    if (y%400 == 0) return true;
    if (y%4 == 0 && y%100 != 0) return true;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int lab[] = {0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d, y, t;
    while (scanf("%d%d%d%d", &t, &d, &m, &y) && d != 0){

        while (t > 0){
            if (isLeap(y)) lab[2] = 29;
            else lab[2] = 28;
            t -= (lab[m++] - d);
            d = 0;
            if (m == 13) m = 1, ++y;
            if (t <= lab[m]) break;
        }
        printf("%d %d %d\n", t, m, y);
    }
}
