#include <bits/stdc++.h>

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