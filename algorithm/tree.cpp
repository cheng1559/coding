#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct Seg {
	std::vector<T> val, lazy;
	std::vector<int> l, r;
	
	inline int lc(int rt) { return rt << 1; }
	inline int rc(int rt) { return rt << 1 | 1; }
	
	inline void pushUp(int rt) {
		val[rt] = val[lc(rt)] + val[rc(rt)];
	}
	
	inline void pushDown(int rt) {
		int llen = r[lc(rt)] - l[lc(rt)] + 1;
		int rlen = r[rc(rt)] - l[rc(rt)] + 1;
		if (lazy[rt]) {
			lazy[lc(rt)] += lazy[rt];
			lazy[rc(rt)] += lazy[rt];
			val[lc(rt)] += lazy[rt] * llen;
			val[rc(rt)] += lazy[rt] * rlen;
			lazy[rt] = 0;
		}
	}
	
	void build(int L, int R, int rt, std::vector<T> &a) {
		l[rt] = L, r[rt] = R;
		if (L == R) {
			val[rt] = a[L];
			return;
		}
		int mid = (l[rt] + r[rt]) >> 1;
		build(l[rt], mid, lc(rt), a);
		build(mid + 1, r[rt], rc(rt), a);
		pushUp(rt);
	}
	
	T query(int L, int R, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) return val[rt];
		if (L > r[rt] || R < l[rt]) return 0;
		pushDown(rt);
		return query(L, R, lc(rt)) + query(L, R, rc(rt));
	}
	
	void update(int L, int R, T x, int rt=1) {
		if (L <= l[rt] && R >= r[rt]) {
			int len = r[rt] - l[rt] + 1;
			val[rt] += x * len;
			lazy[rt] += x;
			return;
		}
		int mid = (l[rt] + r[rt]) >> 1;
		pushDown(rt);
		if (mid >= L) update(L, R, x, lc(rt));
		if (mid < R) update(L, R, x, rc(rt));
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
	int dfn = 0;
	std::vector<std::vector<int>> g;
	Seg<T> seg;
	std::vector<int> fa, dep, size, son, top, idx;
	std::vector<T> val, val2;
	
	void dfs1(int x, int father) {
		dep[x] = dep[father] + 1;
		fa[x] = father;
		for (auto &to : g[x]) {
			if (to == father) { continue; }
			dfs1(to, x);
			size[x] += size[to];
			if (size[son[x]] < size[to]) { son[x] = to; }
		}
	}
	
	void dfs2(int x, int topx) {
		top[x] = topx;
		idx[x] = ++dfn;
		val2[dfn] = val[x];
		
		if (son[x] != 0) { dfs2(son[x], topx); } // 重边则延续该链
		for (auto &to : g[x]) {
			if (to != fa[x] && to != son[x]) { // 轻边则开启一条新链
				dfs2(to, to);
			}
		}
	}
	
	Tree(int n) {
		g.resize(n + 1);
		fa.resize(n + 1);
		dep.resize(n + 1);
		size.resize(n + 1, 1);
		son.resize(n + 1);
		top.resize(n + 1);
		idx.resize(n + 1);
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
	
	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	}

	void update(int u, int v, T x) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			seg.update(idx[top[u]], idx[u], x);
			u = fa[top[u]];
		}
		if (dep[u] > dep[v]) { std::swap(u, v); }
		seg.update(idx[u], idx[v], x);
	}
	
	void updateSubtree(int u, T x) {
		seg.update(idx[u], idx[u] + size[u] - 1, x);
	}
	
	T query(int u, int v) {
		T ans = 0;
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			ans += seg.query(idx[top[u]], idx[u]);
			u = fa[top[u]];
		}
		if (dep[u] > dep[v]) { std::swap(u, v); }
		ans += seg.query(idx[u], idx[v]);
		return ans;
	}
	
	T querySubtree(int u) {
		return seg.query(idx[u], idx[u] + size[u] - 1);
	}
};