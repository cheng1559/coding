#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

struct e {int to, val;};

struct node {
	int id, dis;
	friend bool operator<(node a, node b) {
		return a.dis > b.dis;
	}
};

const ll INF = 1ll << 31;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<e> g[n + 1];
	for (int i = 0; i < n - 1; i ++) {
		int a, b, k;
		std::cin >> a >> b >> k;
		g[a].push_back({b, k});
		g[b].push_back({a, k});
	}
	
	auto dij = [&](int p, int q) {
		vi vis(n + 1);
		vll dis(n + 1, INF);
		std::priority_queue<node> pq;
		pq.push({p, 0});
		dis[p] = 0;
		
		while (pq.size()) {
			node tmp = pq.top();
			pq.pop();
			if (vis[tmp.id]) continue;
			vis[tmp.id] = 1;
			
			for (auto i : g[tmp.id]) {
				if (dis[i.to] > i.val + dis[tmp.id]) {
					dis[i.to] = i.val + dis[tmp.id];
					pq.push({i.to, dis[i.to]});
				}
			}
		}
		
		return dis[q];
	};

	while (m --) {
		int i, j;
		std::cin >> i >> j;
		std::cout << dij(i, j) << "\n";
	}
	
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
}