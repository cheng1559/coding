#include <bits/stdc++.h>

using i64 = long long;

struct Tree {
	int n;
	struct e { int to, val; };
	std::vector<std::vector<e>> g;
	std::vector<int> fath, dep, size, son, top;
	
	void dfs1(int x, int father) {
		dep[x] = dep[father] + 1;
		fath[x] = father;
		for (auto &i : g[x]) {
			int to = i.to;
			if (to == father) { continue; }
			dfs1(to, x);
			size[x] += size[to];
			if (size[son[x]] < size[to]) { son[x] = to; }
		}
	}
	
	void dfs2(int x, int topx) {
		top[x] = topx;
		if (son[x] != 0) { dfs2(son[x], topx); } // 重边则延续该链
		for (auto &i : g[x]) {
			int to = i.to;
			if (to != fath[x] && to != son[x]) { // 轻边则开启一条新链
				dfs2(to, to);
			}
		}
	}
	
	Tree(int n) {
		this->n = n;
		g.resize(n + 1);
		fath.resize(n + 1);
		dep.resize(n + 1);
		size.resize(n + 1, 1);
		son.resize(n + 1, 0);
		top.resize(n + 1);
	}
	
	void add(int x, int father, int val = 1) {
		g[x].emplace_back(e{father, val});
		g[father].emplace_back(e{x, val});
	}
	
	void init(int rt = 1) {
		dfs1(rt, 0);
		dfs2(rt, rt);
	}
	
	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			u = fath[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	}
	
	int len(int u, int v) {
		int k = lca(u, v);
		if (k == v) { return dep[u] - dep[k]; }
		if (k == u) { return 1; }
		return dep[u] - dep[k] + 1;
	}
};

void solve() {
	int n, m, rt = 0;
	std::cin >> n >> m;
	Tree tree(n);
	std::unordered_map<std::string, int> mp;
	std::vector<std::pair<int, int>> r(n - 1);
	std::vector<int> vis(n + 1);
	for (int i = 0, k = 0; i < n - 1; ++i) {
		std::string u, v;
		std::cin >> u >> v;
		if (mp.count(u) == 0) {
			mp[u] = ++k;
		}
		if (mp.count(v) == 0) {
			mp[v] = ++k;
		}
		r[i] = {mp[u], mp[v]};
	}
	for (auto &i : r) {
		tree.add(i.first, i.second);
		vis[i.first] = 1;
	}
	rt = std::find(vis.begin() + 1, vis.end(), 0) - vis.begin();
	tree.init(rt);
	while (m--) {
		std::string u, v;
		std::cin >> u >> v;
		std::cout << tree.len(mp[u], mp[v]) << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}