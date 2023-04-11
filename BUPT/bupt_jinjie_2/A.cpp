#include <bits/stdc++.h>

template<typename T>
class ST {
private:
	struct node {
		T val = 0, lazy = 0;
		int l, r;
	};
	std::vector<node> tree;
	
	inline void push_up(int rt) {
		tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
	}
	
	inline void push_down(int rt) {
		int llen = tree[rt << 1].r - tree[rt << 1].l + 1;
		int rlen = tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1;
		if (tree[rt].lazy) {
			tree[rt << 1].lazy = tree[rt].lazy;
			tree[rt << 1 | 1].lazy = tree[rt].lazy;
			tree[rt << 1].val = tree[rt].lazy * llen;
			tree[rt << 1 | 1].val = tree[rt].lazy * rlen;
			tree[rt].lazy = 0;
		}
	}
	
	void build(int l, int r, int rt, std::vector<T> &a) {
		tree[rt].l = l, tree[rt].r = r;
		if (l == r) {
			tree[rt].val = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, rt << 1, a);
		build(mid + 1, r, rt << 1 | 1, a);
		push_up(rt);
	}
	
public:
	T query(int k, int rt) {
		int l = tree[rt].l, r = tree[rt].r;
		if (l == r) {
			return tree[rt].val;
		}
		int mid = l + r >> 1;
		push_down(rt);
		if (mid >= k) {
			return query(k, rt << 1);
		}
		return query(k, rt << 1 | 1);
	}
	
	T range_query(int L, int R, int rt) {
		int l = tree[rt].l, r = tree[rt].r;
		if (L <= l && R >= r) {
			return tree[rt].val;
		}
		if (L > r || R < l) {
			return 0;
		}
		push_down(rt);
		return range_query(L, R, rt << 1) + range_query(L, R, rt << 1 | 1);
	}
	
	void update(int k, T val, int rt) {
		int l = tree[rt].l, r = tree[rt].r;
		if (l == r) {
			tree[rt].val = val;
			return;
		}
		int mid = l + r >> 1;
		if (mid >= k) update(k, val, rt << 1);
		else update(k, val, rt << 1 | 1);
		push_up(rt);
	}
	
	void range_update(int L, int R, T val, int rt) {
		int l = tree[rt].l, r = tree[rt].r;
		if (L <= l && R >= r) {
			int len = r - l + 1;
			tree[rt].val = val * len;
			tree[rt].lazy = val;
			return;
		}
		int mid = l + r >> 1;
		push_down(rt);
		if (mid >= L) range_update(L, R, val, rt << 1);
		if (mid < R) range_update(L, R, val, rt << 1 | 1);
		push_up(rt);
	}

	ST(std::vector<T> &a) {
		int n = a.size() - 1;
		tree.resize(n << 2);
		build(1, n, 1, a);
	}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, q;
	std::cin >> n >> q;
	vi a(n + 1, 1);
	ST<int> st(a);
	while (q --) {
		int l, r, k;
		std::cin >> l >> r >> k;
		st.range_update(l, r, k, 1);
	}
	std::cout << st.range_query(1, n, 1) << "\n";
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
}