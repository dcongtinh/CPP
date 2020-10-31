#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool prime_check(ll n){
	if (n < 2) return false;
	ll m = sqrt(n);
	for (int i = 2; i <= m; ++i){
		if (n%i == 0) return false;
	}
	return true;
}

ll upside_down(ll n){
	vector<int> a;
	while (n){
		a.push_back(n%10);
		n /= 10;
	}
	ll x = 0LL;
	for (auto d : a){
		if (d == 3 || d == 4 || d == 7) return 2020LL;
		if (d == 6) x = x*10LL + 9LL;
		else if (d == 9) x = x*10LL + 6LL;
		else x = x*10LL + d;
	}
	return x;
}

int main(){
	ll n;
	cin >> n;
	if (prime_check(n) && prime_check(upside_down(n))) cout << "yes";
	else cout << "no";
}
