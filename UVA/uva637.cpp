#include <bits/stdc++.h>

using namespace std;

string toStr(int k){
    stringstream s;
    s << k;
    return s.str();
}

int  main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    while (1){
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        printf("Printing order for %d pages:\n", n);
        int k = (n-1)/4 + 1;
        int l = 1, r = 4*k;
        for (int i = 1; i <= k; ++i){
            int x = (r <= n ? r : -1);
            int y = (l <= n ? l : -1);
            if (x > 0 || y > 0) {
                cout << "Sheet " << i << ", front: ";
                cout << (x > 0 ? toStr(x): "Blank") << ", " << (y > 0 ? toStr(y): "Blank") << endl;
            }
            ++l; --r;

            x = (l <= n ? l : -1);
            y = (r <= n ? r : -1);
            if (x > 0 || y > 0){
                cout << "Sheet " << i << ", back : ";
                cout << (x > 0 ? toStr(x): "Blank") << ", " << (y > 0 ? toStr(y): "Blank") << endl;
            }
            ++l; --r;
        }
    }
    return 0;
}
