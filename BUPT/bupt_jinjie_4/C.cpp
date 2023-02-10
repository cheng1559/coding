#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	while (std::cin >> n) {
		vi a(n);
		for (int i = 0; i < n; i ++) std::cin >> a[i];
		ll ans = 0;
		auto f = [&](auto f, int l, int r) {
			if (l == r) return;
			int mid = l + r >> 1, i = l, j = mid + 1;
			f(f, l, mid), f(f, mid + 1, r);
			vi tmp;
			while (i <= mid && j <= r) {
				if (a[i] < a[j]) tmp.push_back(a[i ++]);
				else tmp.push_back(a[j ++]), ans += mid - i + 1;
			}
			while (i <= mid) tmp.push_back(a[i ++]);
			while (j <= r) tmp.push_back(a[j ++]);
			for (int i = 0; i < tmp.size(); i ++) a[i + l] = tmp[i];
		};
		f(f, 0, n - 1);
		std::cout << ans << "\n";
	}
}