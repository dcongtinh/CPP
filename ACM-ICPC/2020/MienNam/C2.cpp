#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

string s;

int main(){
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	getline(cin, s);
	string v1 = "", v2 = "";
	while (v1.size() < n) {
		getline(cin, s);
		v1 += s;
	}
	cout << v1 << endl;
	while (v2.size() < n) {
		getline(cin, s);
		v2 += s;
	}
	cout << v2;
//	getline(cin, s);
//    string s;
//    cin >> s;
//    int res = -1;
//    for (int k = 1; k < s.size(); ++k) {
//    	if (s[k] == s[0]) {
//    		int ck = 0;
//    		int pos = min((res == -1 ? 2*k : k + res + 1), (int)s.size());
//    		for (int i = k+1; i < pos; ++i) {
//    			if (s[i] != s[i-k]) {
//    				k = i;
//    				ck = 1;
//    				res = i;
//    				break;
//				}
//			}
//			k = pos;
//			if (!ck && res == -1) res = k - 1;
//		}
//		else res = k;
//	}
//	for (int i = 0; i <= res; ++i) cout << s[i];
}
