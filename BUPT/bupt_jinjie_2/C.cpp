#include <bits/stdc++.h>

template<typename T>
class ST {
private:
	struct node {
		T len, llen, rlen, ls, rs;
		int l, r;
	};
	std::vector<node> tree;
	std::vector<T> a;
	
	inline void push_up(int rt) {
		node &lc = tree[rt << 1], &rc = tree[rt << 1 | 1], &t = tree[rt];
		t.ls = lc.ls;
		t.rs = rc.rs;
		t.llen = lc.llen;
		t.rlen = rc.rlen;
		t.len = std::max(lc.len, rc.len);
		if (lc.rs < rc.ls) {
			if (lc.llen == lc.r - lc.l + 1) t.llen += rc.llen;
			if (rc.rlen == rc.r - rc.l + 1) t.rlen += lc.rlen;
			t.len = std::max(t.len, lc.rlen + rc.llen);
		}
	}
	
	void build(int l, int r, int rt, std::vector<T> &a) {
		tree[rt].l = l, tree[rt].r = r;
		if (l == r) {
			tree[rt].len = tree[rt].rlen = tree[rt].llen = 1;
			tree[rt].ls = tree[rt].rs = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, rt << 1, a);
		build(mid + 1, r, rt << 1 | 1, a);
		push_up(rt);
	}
	
public:
	T range_query(int L, int R, int rt=1) {
		node &lc = tree[rt << 1], &rc = tree[rt << 1 | 1];
		int l = tree[rt].l, r = tree[rt].r;
		if (L <= l && R >= r) {
			return tree[rt].len;
		}
		int mid = l + r >> 1, ans = 0;
		if (L <= mid) ans = std::max(ans, range_query(L, R, rt << 1));
		if (R > mid) ans = std::max(ans, range_query(L, R, rt << 1 | 1));
		if (lc.rs < rc.ls) ans = std::max(ans, std::min(mid - L + 1, lc.rlen) + std::min(R - mid, rc.llen));
		return ans;
	}
	
	void update(int k, T val, int rt=1) {
		int l = tree[rt].l, r = tree[rt].r;
		if (l == r) {
			tree[rt].ls = tree[rt].rs = val;
			return;
		}
		int mid = l + r >> 1;
		if (mid >= k) update(k, val, rt << 1);
		else update(k, val, rt << 1 | 1);
		push_up(rt);
	}

	ST(std::vector<T> &_a) {
		a = _a;
		int n = a.size();
		tree.resize(n << 2);
		build(0, n - 1, 1, a);
	}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, q;
	std::cin >> n >> q;
	vi a(n);
	for (int i = 0; i < n; i ++) {
		std::cin >> a[i];
	}
	ST<int> st(a);
	while (q --) {
		char op;
		int a, b;
		std::cin >> op >> a >> b;
		if (op == 'U') {
			st.update(a, b, 1);
		} else {
			std::cout << st.range_query(a, b, 1) << "\n";
		}
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
}