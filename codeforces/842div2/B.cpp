#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, k, cnt = 1;
	std::cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; i ++) {
		std::cin >> a[i];
		if (a[i] == cnt) cnt ++;
	}
	cnt = n - cnt + 1;
	int ans = ceil(1.0 * cnt / k);
	std::cout << ans << "\n";
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