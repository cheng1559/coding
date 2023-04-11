#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, t;
	while (cin >> n >> m) {
		set<int> mp;
		while (n --) cin >> t, mp.insert(t);
		while (m --) cin >> t, mp.insert(t);
		for (auto i : mp) cout << i << " ";
		cout << endl;
	}
}