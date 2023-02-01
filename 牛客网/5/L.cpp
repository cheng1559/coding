#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

ll b[505], x[505];

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	ll n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		std::cin >> b[i] >> x[i];
	}
	vll dp(n + 1, 1e10);
	dp[n] = 0;
	
	for (int i = n; i >= 1; i --) {
		for (int j = 0; j < m; j ++) {
			ll k = i % x[j];
			dp[i - k] = std::min(dp[i] + b[j], dp[i - k]);
		}
	}
	int i = 1;
	while (dp[i] == 1e10) i ++;
	std::cout << dp[i] << "\n";
}