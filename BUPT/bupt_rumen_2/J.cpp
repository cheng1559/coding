#include <bits/stdc++.h>
using namespace std;

int dp[100005], c[105], v[105], n, m, a, b, t;

int main() {
	while (cin >> n) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i ++) {
			cin >> a >> b;
			c[i] = b, v[i] = a;
		}
		
		cin >> m;
		for (int i = 1; i <= n; i ++) {
			for (int j = c[i]; j <= m; j ++) {
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
			}
		}
		cout << dp[m] << endl;
	}
}