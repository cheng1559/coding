#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

void solve() {
	int n, k;
	std::cin >> n >> k;
	vi a(100);
	while (n --) {
		int l, r;
		std::cin >> l >> r;
		if (k < l || k > r) continue;
		for (int i = l; i <= r; i ++) a[i] ++;
	}
	int max = *std::max_element(a.begin(), a.end());
	for (int i = 0; i < 100; i ++) {
		if (a[i] == max && i != k) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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