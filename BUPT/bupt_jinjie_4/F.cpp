#include <bits/stdc++.h>

template<typename T>
class ST {
private:
	struct node {
		T val = 0, lazy = 0;
		int l, r;
	};
	std::vector<node> d;
	std::vector<T> a;
	int n;
	
	inline void up(int rt) {
		d[rt].val = d[rt << 1].val + d[rt << 1 | 1].val;
	}
	
	inline void down(int rt) {
		node &t = d[rt];
		node &lc = d[rt << 1], &rc = d[rt << 1 | 1];
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
		node &t = d[rt];
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
	T query(int L, int R, int rt) {
		node &t = d[rt];
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
		node &t = d[rt];
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
	
	void update(int L, int R, T val, int rt) {
		node &t = d[rt];
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

	ST(std::vector<T> &_a):a(_a) {
		n = a.size() - 1;
		d.resize(n << 2);
		build(1, n);
	}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;
	vll a(n + 1, 1);
	ST<ll> st(a);
	while (m --) {
		int l, r, x;
		std::cin >> l >> r >> x;
		st.update(l, r, x, 1);
	}
	while (q --) {
		int l, r;
		std::cin >> l >> r;
		std::cout << st.query(l, r, 1) << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
}