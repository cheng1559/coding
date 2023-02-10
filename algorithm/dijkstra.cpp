#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

struct node {
	int id, dis;
	friend bool operator<(node a, node b) {
		return a.dis > b.dis;
	}
};

struct e {
	int to, val;
};

const int INF = (1ll << 31) - 1;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m;
	while (std::cin >> n >> m, m || n) {
		std::vector<e> g[n + 1];
		while (m --) {
			int a, b, x;
			std::cin >> a >> b >> x;
			g[a].push_back({b, x});
			g[b].push_back({a, x});
		}
		auto dij = [&](int p, int q) {
			vi vis(n + 1), dis(n + 1, INF);
			std::priority_queue<node> pq;
			pq.push({p, 0});
			dis[p] = 0;
			
			while (pq.size()) {
				node cur = pq.top();
				pq.pop();
				if (vis[cur.id]) continue;
				vis[cur.id] = 1;
				
				for (auto i : g[cur.id]) {
					if (dis[cur.id] + i.val < dis[i.to]) {
						dis[i.to] = dis[cur.id] + i.val;
						pq.push({i.to, dis[i.to]});
					}
				}
			}
			return dis[q] == INF ? -1 : dis[q];
		};
		std::cout << dij(1, n) << "\n";
	}
}