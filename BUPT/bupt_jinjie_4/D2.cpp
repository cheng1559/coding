#include <bits/stdc++.h>

template<typename T>
class range_BIT {
private:
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
	
public:
	void update(int l, int r, T val) {
		update(r + 1, -val);
		update(l, val);
	}
	
	T query(int i) {
		return sum(i);
	}
	
	range_BIT(std::vector<T> &a) {
		n = a.size() - 1;
		t.resize(n + 1);
		for (int i = 1; i <= n; i ++) {
			update(i, a[i] - a[i - 1]);
		}
	}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	while (std::cin >> n, n) {
		vi a(n + 1, 0);
		range_BIT<int> bit(a);
		for (int i = 0; i < n; i ++) {
			int l, r;
			std::cin >> l >> r;
			bit.update(l, r, 1);
		}
		for (int i = 1; i <= n; i ++) {
			std::cout << bit.query(i) << " ";
		}
		std::cout << "\n";
	}
}