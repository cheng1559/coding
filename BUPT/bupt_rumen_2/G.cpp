#include <bits/stdc++.h>
using namespace std;

const int M = 10005;
int dp[M], n, V, t, w[M], v[M];

int main() {
	scanf("%d", &t);
	while (t --) {
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		
		int a, b;
		scanf("%d %d", &a, &b);
		V = b - a;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d %d", v + i, w + i);
		for (int i = 1; i <= n; i ++) {
			for (int j = w[i]; j <= V; j ++) {
				dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		if (dp[V] == 0x3f3f3f3f) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[V]);
	}
}