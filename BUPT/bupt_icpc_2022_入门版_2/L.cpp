#include <bits/stdc++.h>
using namespace std;

const int M = 1005, inf = 0x7fffffff;
int ma[M][M], dis[M], vis[M];
int main() {
	int n, a, b;
	while (scanf("%d %d %d", &n, &a, &b) == 3) {
		for (int i = 0; i <= 1001; i++) {
			for (int j = 0; j <= 1001; j++) ma[i][j] = inf;
			dis[i] = inf, vis[i] = 0;
		}
		while (n --) {
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);
			ma[a][b] = ma[b][a] = min(ma[b][a], t);
		}
		int start = 0, target = 1001, s, d;
		while (a --) {
			scanf("%d", &s); 
			ma[start][s] = 0;
		}
		while (b --) {
			scanf("%d", &d); 
			ma[d][target] = 0;
		}
		dis[start] = 0;
		while (start != target) {
			int minn = inf, ne = start;
			vis[start] = 1;
			for (int i = 0; i <= 1001; i++) {
				if (ma[start][i] != inf) dis[i] = min(dis[i], ma[start][i] + dis[start]);
				if (!vis[i] && minn > dis[i]) {
					ne = i;
					minn = dis[i];
				}
			}
			if (minn == inf) break;
			start = ne;
		}
		printf("%d\n", dis[target]);
	}
}