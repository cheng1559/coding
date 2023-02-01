#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int k, m, n;
int g[M][M], link[M];
bool vis[M];

bool dfs(int x) {
	for (int i = 1; i <= n; i ++) {
		if (!g[x][i] || vis[i]) continue;
		vis[i] = true;
		if (link[i] == -1 || dfs(link[i])) {
			link[i] = x;
			return true;
		}
	}
	return false;
}

int hungary() {
	int ans = 0;
	memset(link, -1, sizeof link);
	for (int i = 1; i <= m; i ++) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	return ans;
}

int main() {
	while (scanf("%d", &k), k) {
		scanf("%d %d", &m, &n);
		memset(g, 0, sizeof g);
		for (int i = 0; i < k; i ++) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a][b] = 1;
		}
		printf("%d\n", hungary());
	}
}