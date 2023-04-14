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
	
	std::vector<std::vector<e>> g, rev, dag;
	std::vector<int> val, f;
	std::vector<e> m;
	
	void add(int u, int v, T x) {
		g[u].emplace_back(e{u, v, x});
		rev[v].emplace_back(e{u, v, x});
		m.emplace_back(e{u, v, x});
	}
	
	Graph(int n) {
		this->n = n;
		g.resize(n + 1);
		rev.resize(n + 1);
		val.resize(n + 1);
		dag.resize(n + 1);
		f.resize(n + 1);
	}
	
	void init() {
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
				dag[f[i.from]].emplace_back(e{f[i.from], f[i.to], i.val});
			}
		}
	}
	
	i64 kosaraju() {
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
		auto dfs = [&](auto dfs, int x) -> T {
			dp[x] = val[x];
			for (auto &i : dag[x]) {
				dp[x] = std::max(dp[x], dfs(dfs, i.to));
			}
			return dp[x];
		};
		dfs(dfs, 1);
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
		g.add(u, v, 1);
	}
	g.init();
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