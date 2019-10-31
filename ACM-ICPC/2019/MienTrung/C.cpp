#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int d1 = gcd(x1, y1);
        int d2 = gcd(x2, y2);
        if (d1 == 0 && d2 == 0){
            cout << "YES\n";
            continue;
        }
        if (d1 && d2){
            if (x2%d1 == 0 && y2%d1 == 0 && x1%d2 == 0 && y1%d2 == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        cout << "NO\n";
    
        
    }
}