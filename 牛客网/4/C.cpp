#include <bits/stdc++.h>
#define int long long

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int w[104], v[104], dp[104];
int is[104], a[104];
signed main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i ++) std::cin >> w[i] >> v[i];
	for (int i = 0; i < n; i ++) {
		for (int j = m; j >= w[i]; j --) {
			dp[j] = std::max(dp[j - w[i]] + v[i], dp[j]);
		}
	}
	int vmax = dp[m];
	
	for (int k = 0; k < n; k ++) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i ++) {
			if (i == k) continue;
			for (int j = m; j >= w[i]; j --) {
				if (dp[j - w[i]] + v[i] > dp[j]) {
					dp[j] = dp[j - w[i]] + v[i];
				}
			}
		}
		if (dp[m] < vmax) is[k] = 1;
	}
	
	for (int k = 0; k < n; k ++) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i ++) {
			if (i == k) continue;
			for (int j = m - w[k]; j >= w[i]; j --) {
				if (dp[j - w[i]] + v[i] > dp[j]) {
					dp[j] = dp[j - w[i]] + v[i];
				}
			}
		}
		if (is[k]) std::cout << 0 << "\n";
		else std::cout << vmax - dp[m - w[k]] - v[k] + 1 << "\n";
	}
}