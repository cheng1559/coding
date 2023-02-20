#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

void solve() {
	ll x, y;
	std::cin >> x >> y;
	int n = (x - y) << 1;
	std::cout << n << "\n";
	for (ll i = y; i <= x; i ++) {
		std::cout << i << " ";
	}
	for (ll i = x - 1; i > y; i --) {
		std::cout << i << " ";
	}
	std::cout << "\n";
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