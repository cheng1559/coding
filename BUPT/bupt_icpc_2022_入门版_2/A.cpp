#include <bits/stdc++.h>
using namespace std;

int to[105][105], dp[105][105];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T --) {
		memset(to, 0, sizeof to);
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j <= i; j++)
				scanf("%d", &to[i][j]);
		for (int i = 0; i < n; i++) dp[n - 1][i] = to[n - 1][i];
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + to[i][j];
			}
		}
		printf("%d\n", dp[0][0]);
	}
}