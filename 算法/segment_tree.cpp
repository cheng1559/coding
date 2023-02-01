#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

template<typename T>
class SegmentTree {
private:
	struct unit {
		T val = 0, lazy = 0;
		int l, r;
	};
	std::vector<unit> d;
	std::vector<T> a;
	inline unit& lc(int rt) { return d[rt << 1]; }
	inline unit& rc(int rt) { return d[rt << 1 | 1]; }
	
	size_t size;
	
	inline void up(int rt) {
		d[rt].val = d[rt << 1].val + d[rt << 1 | 1].val;
	}
	
	inline void down(int rt) {
		unit &t = d[rt];
		unit &lc = d[rt << 1], &rc = d[rt << 1 | 1];
		int llen = lc.r - lc.l + 1;
		int rlen = rc.r - rc.l + 1;
		if (t.lazy) {
			lc.lazy += t.lazy;
			rc.lazy += t.lazy;
			lc.val += t.lazy * llen;
			rc.val += t.lazy * rlen;
			t.lazy = 0;
		}
	}
	
	void build(int l, int r, int rt=1) {
		unit &t = d[rt];
		t.l = l, t.r = r;
		if (l == r) {
			t.val = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
		up(rt);
	}
	
public:
	T query(int L, int R, int rt=1) {
		unit &t = d[rt];
		int l = t.l, r = t.r;
		if (L <= l && R >= r) return t.val;
		if (L > r || R < l) return 0;
		int mid = l + r >> 1;
		down(rt);
		T ans = 0;
		if (L <= mid) ans += query(L, R, rt << 1);
		if (R > mid) ans += query(L, R, rt << 1 | 1);
		return ans;
	}
	
	void update(int n, T val, int rt=1) {
		unit &t = d[rt];
		int l = t.l, r = t.r;
		if (l == r) {
			t.val += val;
			return;
		}
		int mid = l + r >> 1;
		if (n <= mid) update(n, val, rt << 1);
		else update(n, val, rt << 1 | 1);
		up(rt);
	}
	
	void update(int L, int R, T val, int rt=1) {
		unit &t = d[rt];
		int l = t.l, r = t.r;
		if (L <= l && R >= r) {
			t.val += val * (r - l + 1);
			t.lazy += val;
			return;
		}
		int mid = l + r >> 1;
		down(rt);
		if (L <= mid) update(L, R, val, rt << 1);
		if (R > mid) update(L, R, val, rt << 1 | 1);
		up(rt);
	}

	SegmentTree(std::vector<T> &_a):a(_a) {
		size = a.size() - 1;
		d.resize(size << 2);
		build(1, size);
	}
};

using sg = SegmentTree<int>;
