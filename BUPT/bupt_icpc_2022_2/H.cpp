#include <bits/stdc++.h>
using namespace std;

int dp[2005], c[2005], w[2005], T, n, m, p, h, t;

int main() {
	cin >> T;
	while (T --) {
		int idx = 0;
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i < m; i ++) {
			cin >> p >> h >> t;
			int r = 1;
			while (t >= r) c[++ idx] = p * r, w[idx] = h * r, t -= r, r <<= 1;
			if (t) c[++ idx] = p * t, w[idx] = h * t;
		}
		for (int i = 1; i <= idx; i ++) {
			for (int j = n; j >= c[i]; j --) {
				dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
			}
		}
		cout << dp[n] << endl;
	}
}