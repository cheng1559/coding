#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	vi a(n + 1), c1(n + 1), c2(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	c1[1] = a[1] == 2;
	c2[n] = a[n] == 2;
	for (int i = 2; i <= n; i ++) {
		c1[i] = c1[i - 1] + (a[i] == 2);
		c2[n - i + 1] = c2[n - i + 2] + (a[n - i + 1] == 2);
	}	
	for (int i = 1; i <= n - 1; i ++) {
		if (c1[i] == c2[i + 1]) {
			std::cout << i << "\n";
			return;
		}
	}
	std::cout << -1 << "\n";
	
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