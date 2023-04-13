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
	
	void add(int x, int father, int val) {
		g[father].emplace_back(e{x, val});
		g[x].emplace_back(e{father, val});
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
};


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T --) {
		solve();
	}
}