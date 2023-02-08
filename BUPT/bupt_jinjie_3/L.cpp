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
	while (std::cin >> n >> m) {
		std::vector<e> g[n];
		while (m --) {
			int a, b;
			std::cin >> a >> b;
			g[a].push_back({b, 1});
			g[b].push_back({a, 1});
		}
		auto dij = [&](int p) {
			vi vis(n), dis(n, INF);
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
			return *std::max_element(dis.begin(), dis.end());
		};
		int flag = 1;
		for (int i = 0; i < n; i ++) {
			if (dij(i) > 7) {
				flag = 0;
				break;
			} 
		}
		std::cout << (flag ? "Yes" : "No") << "\n";
	}
}