#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, m, d;
	std::cin >> n >> m >> d;
	vi p(n), a(m + 1);
	int ans = 1e9;
	std::unordered_map<int, int> mp;
	for (int i = 0; i < n; i ++) std::cin >> p[i], mp[p[i]] = i;
	for (int i = 1; i <= m; i ++) std::cin >> a[i];
	
	vi t(m + 2);
	t[0] = -1, t[m + 1] = n;
	for (int i = 1; i <= m; i ++) t[i] = mp[a[i]];
	
	for (int i = 2; i <= m; i ++) {
		if (t[i] < t[i - 1] || t[i] - t[i - 1] > d) {
			std::cout << 0 << "\n";
			return;
		}
		ans = std::min(ans, t[i] - t[i - 1]);
		if (t[i + 1] - t[i - 2] - 3 >= d)
			ans = std::min(ans, d - t[i] + t[i - 1] + 1);
	}
	std::cout << ans << "\n";
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}