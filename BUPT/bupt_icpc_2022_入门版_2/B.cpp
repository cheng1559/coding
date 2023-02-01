#include <bits/stdc++.h>
using namespace std;

const int M = 10004;
int k[M], dp[M], n, ans;
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(dp, 0, sizeof dp);
		ans = 0;
		for (int i = 0; i < n; i++) scanf("%d", k + i);
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (k[i] > k[j]) dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
		printf("%d\n", ans);
	}
}