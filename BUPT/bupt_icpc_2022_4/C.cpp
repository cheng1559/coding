#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	string s;
	while (cin >> T) {
		unordered_map<string, int> mp;
		while (T --) cin >> s, mp[s];
		cout << mp.size() << endl;
	}
}