#include <bits/stdc++.h>

template<typename T>
class BIT {
public:
	int n;
	std::vector<T> t;
	int lowbit(int x) const { return x & -x; }
	
	void update(int i, T val) {
		while (i <= n) {
			t[i] += val;
			i += lowbit(i);
		}
	}
	
	T sum(int i) {
		T ans = 0;
		while (i > 0) {
			ans += t[i];
			i -= lowbit(i);
		}
		return ans;
	}
	
	T query(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
	
	BIT(std::vector<T> &a) {
		n = a.size() - 1;
		t.resize(n + 1);
		for (int i = 1; i <= n; i ++) {
			update(i, a[i]);
		}
	}
};

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	while (std::cin >> n) {
		vi a(n), b(n + 1);
		for (int i = 0; i < n; i ++) std::cin >> a[i];
		BIT bit(b);
		ll ans = 0;
		for (int i = 0; i < n; i ++) {
			bit.update(a[i], 1);
			ans += bit.query(a[i] + 1, n);
		}
		std::cout << ans << "\n";
	}
}