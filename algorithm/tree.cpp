#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct Seg {
	std::vector<T> val, lazy;
	std::vector<int> l, r;
	
	inline void pushUp(int rt) {
		val[rt] = val[rt << 1] + val[rt << 1 | 1];
	}
	
	inline void pushDown(int rt) {
		int llen = r[rt << 1] - l[rt << 1] + 1;
		int rlen = r[rt << 1 | 1] - l[rt << 1 | 1] + 1;
		if (lazy[rt]) {
			lazy[rt << 1] += lazy[rt];
			lazy[rt << 1 | 1] += lazy[rt];
			val[rt << 1] += lazy[rt] * llen;
			val[rt << 1 | 1] += lazy[rt] * rlen;
			lazy[rt] = 0;
		}
	}
	
	void build(int L, int R, int rt, std::vector<T> &a) {
		l[rt] = L, r[rt] = R;
		if (L == R) {
			val[rt] = a[L];
			return;
		}
		int mid = l[rt] + r[rt] >> 1;
		build(l, mid, rt << 1, a);
		build(mid + 1, r, rt << 1 | 1, a);
		pushUp(rt);
	}
	
	T query(int L, int R, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) return val[rt];
		if (L > r[rt] || R < l[rt]) return 0;
		pushDown(rt);
		return query(L, R, rt << 1) + query(L, R, rt << 1 | 1);
	}
	
	void update(int L, int R, T x, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) {
			int len = r[rt] - l[rt] + 1;
			val[rt] += x * len;
			lazy[rt] += x;
			return;
		}
		int mid = l[rt] + r[rt] >> 1;
		pushDown(rt);
		if (mid >= L) update(L, R, x, rt << 1);
		if (mid < R) update(L, R, x, rt << 1 | 1);
		pushUp(rt);
	}
	
	void init(std::vector<T> &a) {
		int n = a.size() - 1;
		val.resize(n << 2);
		lazy.resize(n << 2);
		l.resize(n << 2);
		r.resize(n << 2);
		build(1, n, 1, a);
	}

	Seg(std::vector<T> &a) {
		init(a);
	}
	
	Seg() {}
};

template<typename T>
struct Tree {
	int dfn = 0, n;
	std::vector<std::vector<int>> g;
	Seg<T> seg;
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
		seg.init(val);
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

	void update(int u, int v, T x) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			seg.update(ipt[top[u]], ipt[u], x);
			u = fath[top[u]];
		}
		if (dep[u] > dep[v]) { std::swap(u, v); }
		seg.update(ipt[u], ipt[v], x);
	}
	
	void updateSubtree(int u, T x) {
		seg.update(ipt[u], ipt[u] + size[u] - 1, x);
	}
	
	T query(int u, int v, T x) {
		T ans = 0;
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			ans += seg.query(ipt[top[u]], ipt[u]);
			u = fath[top[u]];
		}
		if (dep[u] > dep[v]) { std::swap(u, v); }
		ans += seg.query(ipt[u], ipt[v]);
		return ans;
	}
	
	T querySubtree(int u, T x) {
		return seg.query(ipt[u], ipt[u] + size[u] - 1);
	}
};