#include <bits/stdc++.h>
using namespace std;

const int M = 105;
int n, m, k, T, c, l;
int g[M][M], link[M], b[M][M], book[M * M][2];
bool vis[M];

bool dfs(int x) {
	for (int i = 1; i <= m; i ++) {
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
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	return ans;
}

int main() {
	while (~scanf("%d%d%d", &n, &m, &k)) {
		c = 0;
		memset(g, 0, sizeof g);
		memset(b, 0, sizeof b);
		memset(book, 0, sizeof book);
		for (int i = 0; i < k; i ++) {
			int x, y;
			scanf("%d%d", &book[i][0], &book[i][1]);
			g[book[i][1]][book[i][0]] = 1;
		}
		l = hungary();
		for (int i = 0; i < k; i ++) {
			g[book[i][1]][book[i][0]] = 0;
			c += hungary() != l;
			g[book[i][1]][book[i][0]] = 1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", ++ T, c, l);
	}
}