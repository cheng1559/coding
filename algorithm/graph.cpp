#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 1e9;
template <typename T>
struct Graph {
	int n;
	struct e { int from, to; };

	std::vector<std::vector<e>> g, rev, dag;
	std::vector<int> val, f, val2;
	std::vector<e> m;
	
	void add(int u, int v) {
		g[u].emplace_back(e{u, v});
		rev[v].emplace_back(e{v, u});
		m.emplace_back(e{u, v});
	}
	
	Graph(int n) {
		this->n = n;
		g.resize(n + 1);
		rev.resize(n + 1);
		val.resize(n + 1);
		val2.resize(n + 1);
		dag.resize(n + 1);
		f.resize(n + 1);
	}
	
	void kosaraju() {
		val2 = val;
		std::stack<int> st;
		std::vector<int> vis(n + 1);
		auto dfs1 = [&](auto dfs1, int x) {
			if (vis[x]) { return; }
			vis[x] = 1;
			for (auto &i : rev[x]) {
				dfs1(dfs1, i.to);
			}
			st.push(x);
		};
		
		auto dfs2 = [&](auto dfs2, int x, int y) {
			if (!vis[x]) { return; }
			f[x] = y;
			val2[y] = std::max(val[x], val2[y]);
			vis[x] = 0;
			for (auto &i : g[x]) {
				dfs2(dfs2, i.to, y);
			}
		};
		
		for (int i = 1; i <= n; ++i) {
			dfs1(dfs1, i);
		}
		while (st.size()) {
			dfs2(dfs2, st.top(), st.top());
			st.pop();
		}
		for (auto &i : m) {
			if (f[i.from] != f[i.to]) {
				dag[f[i.from]].emplace_back(e{f[i.from], f[i.to]});
			}
		}
	}
	
	i64 count() {
		std::unordered_map<int, int> cnt;
		for (int i = 1; i <= n; ++i) { ++cnt[f[i]]; }
		i64 ans = 0;
		for (auto &i : cnt) {
			ans += 1LL * i.second * (i.second - 1) / 2;
		}
		return ans;
	}
	
	std::vector<T> query() {
		std::vector<T> dp(n + 1);
		auto dfs = [&](auto dfs, int x) {
			if (dp[x]) return;
			dp[x] = val2[x];
			for (auto &i : dag[x]) {
				dfs(dfs, i.to);
				dp[x] = std::max(dp[x], dp[i.to]);
			}
		};
		for (int i = 1; i <= n; ++i) {
			if (!dp[i]) {
				dfs(dfs, i);
			}
		}
		return dp;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	Graph<int> g(n);
	for (int i = 1; i <= n; ++i) {
		std::cin >> g.val[i];
	}
	while (m--) {
		int u, v;
		std::cin >> u >> v;
		g.add(u, v);
	}
	g.kosaraju();
	auto dp = g.query();
	for (int i = 1; i <= n; ++i) {
		std::cout << dp[i] << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) { solve(); }
}