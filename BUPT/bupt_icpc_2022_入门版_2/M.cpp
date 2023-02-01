#include <bits/stdc++.h>
using namespace std;

const int M = 1005, inf = 0x7fffffff;
int g[M][M], vis[M], dis[M], n, m, e;

void init() {
	for (int i = 0; i <= n; i ++) {
		vis[i] = 0;
		dis[i] = inf;
		for (int j = 0; j <= n; j ++) g[i][j] = inf;
	}
}

int dijkstra() {
	int s = 0;
	dis[0] = 0;
	while (s != e) {
		vis[s] = 1;
		int minn = inf, ne = s;
		for (int i = 0; i <= n; i ++) {
			if (g[s][i] != inf) dis[i] = min(dis[i], dis[s] + g[s][i]);
			if (!vis[i] && dis[i] < minn) minn = dis[i], ne = i;
		}
		if (minn == inf) break;
		s = ne;
	}
	if (dis[e] == inf) return -1;
	return dis[e];
}

int main() {
	while (~scanf("%d %d %d", &n, &m, &e)) {
		init();
		while (m --) {
			int p, q, t;
			scanf("%d %d %d", &p, &q, &t);
			g[p][q] = min(g[p][q], t);
		}
		int w, r;
		scanf("%d", &w);
		while (w --) {
			scanf("%d", &r);
			g[0][r] = 0;
		}
		printf("%d\n", dijkstra());
	}
}