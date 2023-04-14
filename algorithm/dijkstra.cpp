#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 1e9;

template <typename T>
struct Graph {
	int n;
	struct e { int from, to; T val; };
	struct node {
		int id;
		T dis;
		friend bool operator<(node a, node b) { return a.dis > b.dis; }
	};
	
	std::vector<std::vector<e>> g;
	
	void add(int u, int v, T x) {
		g[u].emplace_back(e{u, v, x});
	}
	
	Graph(int n) {
		this->n = n;
		g.resize(n + 1);
	}
	
	int dijkstra(int p, int q) {
		std::vector<int> vis(n + 1), dis(n + 1, INF);
		std::priority_queue<node> pq;
		pq.push({p, 0});
		dis[p] = 0;
		while (pq.size()) {
			node cur = pq.top();
			pq.pop();
			if (vis[cur.id]) continue;
			vis[cur.id] = 1;
			
			for (auto &i : g[cur.id]) {
				if (dis[cur.id] + i.val < dis[i.to]) {
					dis[i.to] = dis[cur.id] + i.val;
					pq.push({i.to, dis[i.to]});
				}
			}
		}
		return dis[q] == INF ? -1 : dis[q];
	};
};

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m;
	while (std::cin >> n >> m, m || n) {
		Graph<int> g(n + 1);
		while (m --) {
			int u, v, x;
			std::cin >> u >> v >> x;
			g.add(u, v, x);
			g.add(v, u, x);
		}
		std::cout << g.dijkstra(1, n) << "\n";
	}
}