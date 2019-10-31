#include <bits/stdc++.h>
#define oo 1000000007

using namespace std;

void find_num(){
    int c[10], _min = oo;
    vector<int> num;
    for (int i = 0; i < 10; ++i){
        cin >> c[i];
        _min = min(_min, c[i]);
    }
    for (int i = 0; i < 10; ++i){
        if (c[i] == _min) num.push_back(i);
    }
    for (int i = 1; i < 10; ++i){
        if (!c[i]) {
            cout << i << endl;
            return;
        }
    }
    if (!num[0]){
        if (num.size() == 1){

            cout << 1;
            for (int i = 0; i <= _min; ++i)
                cout << 0;
            cout << endl;
            return;
        }
        for (int i = 0; i <= _min; ++i)
            cout << num[1];
        cout << endl;
        return;
    }
    for (int i = 0; i <= _min; ++i)
        cout << num[0];
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        find_num();
    }
}