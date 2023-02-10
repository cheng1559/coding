#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	int a = 0, b = 0, k = 1, r = 1;
	while (n - k >= 0) {
		if (r % 4 < 2) a += k;
		else b += k;
		n -= k;
		k ++;
		r ++;
	}
	if (r % 4 < 2) a += n;
	else b += n;
	std::cout << a << " " << b << "\n";
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}