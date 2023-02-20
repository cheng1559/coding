#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

void solve() {
	ll a, b, n, m;
	std::cin >> a >> b >> n >> m;
	ll ans = 0;

	if (a * m <= b * (m + 1)) {
		ans += n / (m + 1) * m * a;
		if (a < b) {
			ans += (n - n / (m + 1) * (m + 1)) * a;
		} else {
			ans += (n - n / (m + 1) * (m + 1)) * b;
		}
	}
	else {
		ans += b * n;
	}
	
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