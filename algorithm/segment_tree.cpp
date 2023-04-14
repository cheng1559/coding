#include <bits/stdc++.h>

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