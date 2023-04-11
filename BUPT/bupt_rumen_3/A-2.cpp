#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> s;
		for (int i = 1; i <= n; i ++) s.push_back(i);
		do {
			for (auto i : s) printf("%d ", i);
			puts("");
		} while (next_permutation(s.begin(), s.end()));
	}
}