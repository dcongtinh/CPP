#include <bits/stdc++.h>
#define ll long long
#define y0 HNhu_y0
#define y1 HNhu_y1
#define prev HNhu_prev
using namespace std;

template <class T>
T toNum (string s) {
	stringstream ss (s);
	T result;
	ss >> result;	
	return result;
}

template <class T>
string toString (T d) {
	return to_string (d);
}

string input (string prompt) {
	cout << prompt;
	string s;
	cin >> s;
	return s;
}
