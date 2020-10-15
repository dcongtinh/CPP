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
    #endif // ONLINE_JUDGE

    int nT;
    scanf("%d", &nT);
    int lab[] = {0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int iT = 1; iT <= nT; ++iT){
        int m, d, y;
        scanf("%2d%2d%4d", &m, &d, &y);

        int t = 280;
        while (t > 0){
            if (isLeap(y)) lab[2] = 29;
            else lab[2] = 28;
            t -= (lab[m++] - d);
            d = 0;
            if (m == 13) m = 1, ++y;
            if (t <= lab[m]) break;
        }
        printf("%d %02d/%02d/%d ", iT, m , t, y);
        if (m == 1 && t >= 21 || m == 2 && t <= 19) puts("aquarius");
        if (m == 2 && t >= 20 || m == 3 && t <= 20) puts("pisces");
        if (m == 3 && t >= 21 || m == 4 && t <= 20) puts("aries");
        if (m == 4 && t >= 21 || m == 5 && t <= 21) puts("taurus");
        if (m == 5 && t >= 22 || m == 6 && t <= 21) puts("gemini");
        if (m == 6 && t >= 22 || m == 7 && t <= 22) puts("cancer");
        if (m == 7 && t >= 23 || m == 8 && t <= 21) puts("leo");
        if (m == 8 && t >= 22 || m == 9 && t <= 23) puts("virgo");
        if (m == 9 && t >= 24 || m == 10 && t <= 23) puts("libra");
        if (m == 10 && t >= 24 || m == 11 && t <= 22) puts("scorpio");
        if (m == 11 && t >= 23 || m == 12 && t <= 22) puts("sagittarius");
        if (m == 12 && t >= 23 || m == 1 && t <= 20) puts("capricorn");
    }
}
