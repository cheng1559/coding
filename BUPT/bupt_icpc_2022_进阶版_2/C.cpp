#include <bits/stdc++.h>


template<typename T>
class SegmentTree {
private:
	struct unit {
		T lmax, rmax, max, ls, rs;
		int l, r;
	};
	std::vector<unit> d;
	
	size_t size;
	
	inline void up(int rt) {
		unit &lc = d[rt << 1], &rc = d[rt << 1 | 1], &t = d[rt];
		t.ls = lc.ls;
		t.rs = rc.rs;
		t.lmax = lc.lmax;
		t.rmax = rc.rmax;
		t.max = std::max(lc.max, rc.max);
		if (lc.rs < rc.ls) {
			if (lc.lmax == lc.r - lc.l + 1) t.lmax += rc.lmax;
			if (rc.rmax == rc.r - rc.l + 1) t.rmax += lc.rmax;
			t.max = std::max(t.max, lc.rmax + rc.lmax);
		}
	}
	
	void build(std::vector<T> &A, int l, int r, int rt=1) {
		unit &t = d[rt];
		t.l = l, t.r = r;
		if (l == r) {
			t.lmax = t.rmax = t.max = 1;
			t.ls = t.rs = A[l];
			return;
		}
		int mid = l + r >> 1;
		build(A, l, mid, rt << 1);
		build(A, mid + 1, r, rt << 1 | 1);
		up(rt);
	}
	
public:
	T query(int L, int R, int rt=1) {
		unit &t = d[rt], &lc = d[rt << 1], &rc = d[rt << 1 | 1];
		int l = t.l, r = t.r;
		if (L <= l && R >= r) return t.max;
		int mid = l + r >> 1;
		T ans = 0;
		if (L <= mid) ans = std::max(ans, query(L, R, rt << 1));
		if (R > mid) ans = std::max(ans, query(L, R, rt << 1 | 1));
		if (lc.rs < rc.ls) ans = std::max(ans, std::min(mid - L + 1, lc.rmax) + std::min(R - mid, rc.lmax));
		return ans;
	}
	
	void update(int n, T val, int rt=1) {
		unit &t = d[rt];
		int l = t.l, r = t.r;
		if (l == r) {
			t.ls = t.rs = val;
			return;
		}
		int mid = l + r >> 1;
		if (n <= mid) update(n, val, rt << 1);
		else update(n, val, rt << 1 | 1);
		up(rt);
	}
	

	SegmentTree(std::vector<T> &A) {
		size = A.size();
		d.resize(size << 2);
		build(A, 0, size - 1);
	}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;
using sg = SegmentTree<int>;

void solve() {
	int n, m;
	std::cin >> n >> m;
	vi A(n);
	for (int i = 0; i < n; i ++) std::cin >> A[i];
	sg t(A);
	while (m --) {
		char op;
		int a, b;
		std::cin >> op >> a >> b;
		if (op == 'U') t.update(a, b);
		else std::cout << t.query(a, b) << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}