#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	ll n;
	std::cin >> n;
	if (n % 2 == 0) {
		std::cout << "No\n";
		return;
	}
	int cur = 1, k = 3 * n + 3 >> 1;
	std::cout << "Yes\n";
	for (int i = 0; i < n; i ++) {
		std::cout << cur << " " << k + i - cur << "\n";
		cur += 2;
		if (i == n / 2) {
			cur = 2;
		}
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