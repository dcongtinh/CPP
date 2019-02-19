#include <bits/stdc++.h>

using namespace std;

char a[200000];
int m = strlen(a);
int s, s1, s2;

bool isLeapyear(){

    int num2Final = (a[m-2]-48)*10 + a[m-1]-48;

    int k = (a[m-4]-48)*1000 + (a[m-3]-48)*100 + (a[m-2]-48)*10 + a[m-1]-48;
    if (k % 400 ==0) return true;

    if (num2Final%4 == 0 && num2Final != 0) return true;

    return false;
}

bool isHuluculu(){
    if (s%3 == 0 && (a[m-1] == '0' || a[m-1] == '5')) return true;
    return false;
}

bool isBulukulu(){
    if ((a[m-1] == '0' || a[m-1] == '5') && abs(s2-s1)%11 == 0 ) return true;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    bool firstline = false;
    while (scanf("%s", a) != EOF){

        if (firstline) printf("\n");
        else firstline = true;
        m = strlen(a);
        s = s1 = s2 = 0;
        for (int i = 0; i < m; ++i){
            s += a[i]-48;
            if (i%2 == 0) s1 += a[i]-48;
            else s2 += a[i]-48;
        }

        bool ok = false;

        if (isLeapyear()){
            ok = true;
            printf("This is leap year.\n");
        }

        if (isHuluculu()){
            ok = true;
            printf("This is huluculu festival year.\n");
        }

        if (isBulukulu() && isLeapyear()){
            ok = true;
            printf("This is bulukulu festival year.\n");
        }

        if (!ok)printf("This is an ordinary year.\n");

    }
    return 0;
}
