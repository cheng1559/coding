#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	int f1 = 0, f2 = 0;
	for (int i = 0; i < n - 1; i ++) {
		if (a[i] == a[i + 1]) f1 ++;
	}
	for (int i = 0; i < m; i ++) {
		if (b[i] == b[i + 1]) f2 ++;
	}
	if (f1 + f2 > 1) {
		std::cout << "NO\n";
	} else if (f1 + f2 == 1 && a[n - 1] == b[m - 1]) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
}