#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int n, m;
int g[M][M], link[M];
bool vis[M];

bool dfs(int x) {
	for (int i = 0; i < m; i ++) {
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
	for (int i = 0; i < n; i ++) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	return ans;
}

int main() {
	int k;
	while (~scanf("%d", &n) && n) {
		
	}
}