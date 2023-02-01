#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int n, k;
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
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d", &n, &k);
		memset(g, 0, sizeof g);
		while (k --) {
			int x, y;
			scanf("%d %d", &x, &y);
			g[x][y] = 1;
		}
		printf("%d\n", n - hungary());
	}

}