#include <bits/stdc++.h>
using namespace std;

const int M = 1005, inf = 0x7fffffff;
int ma[M][M], dis[M], vis[M];
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) ma[i][j] = inf;
			dis[i] = inf, vis[i] = 0;
		}
		while (m --) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ma[a][b] = ma[b][a] = min(ma[b][a], c);
		}
		int start, target;
		scanf("%d%d", &start, &target);
		dis[start] = 0;
		while (start != target) {
			int minn = inf, ne = start;
			vis[start] = 1;
			for (int i = 0; i < n; i++) {
				if (ma[start][i] != inf) dis[i] = min(dis[i], ma[start][i] + dis[start]);
				if (!vis[i] && minn > dis[i]) {
					ne = i;
					minn = dis[i];
				}
			}
			if (minn == inf) break;
			start = ne;
		}
		if (dis[target] == inf) printf("-1\n");
		else printf("%d\n", dis[target]);
	}
}