#include <bits/stdc++.h>

using namespace std;

const int M = 205;
int n, k;
int g[M][M], dp[M][M];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
	
	if (dp[y][x]) return dp[y][x];
	int res = 0;
	for (int i = 1; i <= k; i ++) {
		for (int j = 0; j < 4; j ++) {
			int tx = x + dx[j] * i, ty = y + dy[j] * i;
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (g[ty][tx] > g[y][x]) res = max(res, dfs(tx, ty));
		}
	}
	return dp[y][x] = res + g[y][x];
}

int main() {
	while (cin >> n >> k, ~n && ~k) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cin >> g[i][j];
			}
		}
		cout << dfs(0, 0) << endl;
	}
}