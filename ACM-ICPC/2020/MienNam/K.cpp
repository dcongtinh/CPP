#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t, b;
vector<pair<int, int> > v;
int f[1005][1005];

int main(){
	freopen("input.txt", "r", stdin);
	cin >> t >> b;
	for (int i = 0; i < b; ++i){
		int s, d;
		cin >> s >> d;
		v.push_back({s, d});
	}
//	for (int i = 1; i <= b; ++i) cin >> a[i] >> v[i];
    
    for (int j = 0; j <= t; ++j) f[0][j] = 0;
    
    for (int i = 1; i <= b; ++i) {
        for (int j  = 1; j <= t; ++j) {
            f[i][j] = f[i-1][j];
            if (v[i].first <= j) f[i][j] = max(f[i][j], f[i-1][j-v[i].first] + v[i].second);
        }
    }
    cout << f[b][t];
}
