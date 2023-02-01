#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
	while (cin >> n >> m) {
		vector<int> s;
		for (int i = 1; i <= n; i ++) s.push_back(i);
		while (-- m) next_permutation(s.begin(), s.end());
		for (auto i : s) cout << i << " ";
		cout << endl;
	}
}