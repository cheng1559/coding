#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0, k = 1, r = 1;
	while (n - k >= 0) {
		if (r % 4 < 2) {
			a1 += (k + 1) / 2;
			a2 += k - (k + 1) / 2;
		}
		else {
			b1 += k / 2;
			b2 += k - k / 2;
		}
		n -= k;
		k ++;
		r ++;
	}
	if (r % 4 < 2) {
		a1 += (n + 1) / 2;
		a2 += n - (n + 1) / 2;
	}
	else {
		b1 += n / 2;
		b2 += n - n / 2;
	}
	std::cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}