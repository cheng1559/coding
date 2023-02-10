#include <bits/stdc++.h>

template<typename T>
class ST {
private:
	struct node {
		T val = 0;
		int l, r;
	};
	std::vector<node> d;
	std::vector<T> a;
	int n;
	
	inline void up(int rt) {
		d[rt].val = std::max(d[rt << 1].val, d[rt << 1 | 1].val);
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
		T ans = 0;
		if (L <= mid) ans = std::max(ans, query(L, R, rt << 1));
		if (R > mid) ans = std::max(ans, query(L, R, rt << 1 | 1));
		return ans;
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
	int n, q;
	std::cin >> n;
	vi a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	ST<int> st(a);
	std::cin >> q;
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