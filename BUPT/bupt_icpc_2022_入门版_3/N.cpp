#include <bits/stdc++.h>

using namespace std;

const int M = 205, MOD = 10000;
int n, m, T, k;
int g[M][M], dp[M][M];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
	if (dp[y][x] >= 0) return dp[y][x];
	dp[y][x] = 0;
	for (int dx = 0; dx <= g[y][x]; dx ++) {
		for (int dy = 0; dx + dy <= g[y][x]; dy ++) {
			int tx = x + dx, ty = y + dy;
			if (tx <= 0 || tx > m || ty <= 0 || ty > n) continue;
			dp[y][x] = (dp[y][x] + dfs(tx, ty)) % 10000;
		}
	}
	return dp[y][x];
}

int main() {
	cin >> T;
	while (T --) {
		scanf("%d%d", &n, &m);
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				cin >> g[i][j];
			}
		}
		dp[n][m] = 1;
		cout << dfs(1, 1) << endl;
	}
}