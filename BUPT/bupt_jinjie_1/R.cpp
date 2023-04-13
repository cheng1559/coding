#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct SEG {
	std::vector<T> val, sum;
	std::vector<int> l, r, vis;
	
	inline void pushUp(int rt) {
		val[rt] = val[rt << 1] + val[rt << 1 | 1];
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	
	inline void pushDown(int rt) {
		if (vis[rt]) {
			vis[rt << 1] = vis[rt << 1 | 1] = vis[rt];
			if (vis[rt << 1]) {
				sum[rt << 1] = val[rt << 1]; 
			} else {
				sum[rt << 1] = 0;
			}
			if (vis[rt << 1 | 1]) {
				sum[rt << 1 | 1] = val[rt << 1 | 1];
			} else {
				sum[rt << 1 | 1] = 0;
			}
			vis[rt] = 0;
		}
	}
	
	void build(int L, int R, int rt, std::vector<T> &a) {
		l[rt] = L, r[rt] = R;
		if (L == R) {
			val[rt] = a[L];
			return;
		}
		int mid = L + R >> 1;
		build(L, mid, rt << 1, a);
		build(mid + 1, R, rt << 1 | 1, a);
		pushUp(rt);
	}
	
	T query(int L, int R, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) return sum[rt];
		if (L > r[rt] || R < l[rt]) return 0;
		pushDown(rt);
		return query(L, R, rt << 1) + query(L, R, rt << 1 | 1);
	}
	
	void update(int L, int R, T _val, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) {
			int len = r[rt] - l[rt] + 1;
			vis[rt] = _val;
			if (vis[rt]) {
				sum[rt] = val[rt];
			} else {
				sum[rt] = 0;
			}
			return;
		}
		int mid = l[rt] + r[rt] >> 1;
		pushDown(rt);
		if (mid >= L) update(L, R, _val, rt << 1);
		if (mid < R) update(L, R, _val, rt << 1 | 1);
		pushUp(rt);
	}

	SEG(std::vector<T> &a) {
		init(a);
	}
	
	SEG() {}
	
	void init(std::vector<T> &a) {
		int n = a.size() - 1;
		l.resize(n << 2);
		r.resize(n << 2);
		val.resize(n << 2);
		vis.resize(n << 2);
		sum.resize(n << 2);
		build(1, n, 1, a);
	}
};

template<typename T>
struct Tree {
	int dfn = 0, n;
	std::vector<std::vector<int>> g;
	SEG<T> seg;
	std::vector<int> fath, dep, size, son, top, ipt;
	std::vector<T> val, val2;
	
	void dfs1(int x, int father) {
		dep[x] = dep[father] + 1;
		fath[x] = father;
		for (auto &to : g[x]) {
			if (to == father) { continue; }
			dfs1(to, x);
			size[x] += size[to];
			if (size[son[x]] < size[to]) { son[x] = to; }
		}
	}
	
	void dfs2(int x, int topx) {
		top[x] = topx;
		ipt[x] = ++dfn;
		val2[dfn] = val[x];
		
		if (son[x] != 0) { dfs2(son[x], topx); } // 重边则延续该链
		for (auto &to : g[x]) {
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
		ipt.resize(n + 1);
		val.resize(n + 1);
		val2.resize(n + 1);
	}
	
	void add(int x, int father) {
		g[father].emplace_back(x);
		g[x].emplace_back(father);
	}
	
	void init(int rt = 1) {
		dfs1(rt, 0);
		dfs2(rt, rt);
		seg.init(val2);
	}

	void update(int u, int v, T _val) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			seg.update(ipt[top[u]], ipt[u], _val);
			u = fath[top[u]];
		}
		if (dep[u] > dep[v]) { std::swap(u, v); }
		seg.update(ipt[u], ipt[v], _val);
	}
	
	void updateSubtree(int u, T _val) {
		seg.update(ipt[u], ipt[u] + size[u] - 1, _val);
	}
	
	T query(int u, int v) {
		return seg.query(ipt[u], ipt[v]);
	}
	
	T querySum() {
		return seg.sum[1];
	}
};

void solve() {
	int n, q;
	std::cin >> n;
	std::vector<int> a(n + 1);
	
	Tree<int> tree(n);
	for (int i = 1; i <= n; ++i) {
		std::cin >> tree.val[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		tree.add(u, v);
	}
	
	tree.init(1);
	
	std::cin >> q;
	while (q--) {
		int op, u, v;
		std::cin >> op;
		if (op == 1) {
			std::cin >> u >> v;
			tree.update(u, v, 1);
		} else if (op == 2) {
			std::cin >> u;
			tree.update(u, u, 0);
		} else if (op == 3) {
			std::cin >> u;
			tree.updateSubtree(u, 1);
		}
		
		std::cout << tree.querySum() << "\n";
	}
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}