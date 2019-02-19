#include <bits/stdc++.h>

using namespace std;

int n;
bool found;

bool check(int tu, int mau){
    int d[10];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < 5; ++i){
        ++d[tu%10];
        ++d[mau%10];
        tu /= 10;\
        mau /= 10;
    }
    for (int i = 0; i < 10; ++i)
        if (d[i] != 1) return false;

    return true;
}

void printfResult(int tu, int mau){
    if (tu <= 9999) printf("0%d", tu);
    else printf("%d", tu);
    printf(" / ");
    if (mau <= 9999) printf("0%d", mau);
    else printf("%d", mau);
    printf(" = %d\n", n);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    bool firstline = true;
    while (scanf("%d", &n) && (n!=0)){
        found = false;
        if (!firstline) printf("\n");
        else firstline = false;

        for (int mau = 1234; mau < 98765; ++mau){
            int tu = mau*n;
            if (tu > 98765) break;
            if (check(tu, mau)) {
                printfResult(tu, mau);
                found = true;
            }
        }
        if (!found) printf("There are no solutions for %d.\n", n);
    }
}
