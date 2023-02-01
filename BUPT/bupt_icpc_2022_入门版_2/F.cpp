#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int dp[M], n, V, t, w[M], v[M];

int main() {
	scanf("%d", &t);
	while (t --) {
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &V);
		for (int i = 1; i <= n; i ++) scanf("%d", v + i);
		for (int i = 1; i <= n; i ++) scanf("%d", w + i);
		for (int i = 1; i <= n; i ++) {
			for (int j = V; j >= w[i]; j --) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		printf("%d\n", dp[V]);
	}
}