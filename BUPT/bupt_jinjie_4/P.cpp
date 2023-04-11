#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 2), b(n + 2);
	std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> b[i];
	}
	
	for (int len = 1; len <= n; len ++) {
		for (int i = 1, j = len; j <= n; i ++, j ++) {
			dp[i][j] = 1e9;
			for (int k = i; k <= j; k ++) {
				dp[i][j] = std::min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
			}
		}
	}
	std::cout << dp[1][n] << "\n";
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	//std::cout << std::fixed << std::setprecision(2);
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; i ++) {
		std::cout << "Case #" << i << ": ";
		solve();
	}
}