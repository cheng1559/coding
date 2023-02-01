#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	ll x, y, k, n, T;
	ll t = 0, sumk = 0;
	std::cin >> x >> y >> k >> n >> T;
	vll a(n);
	for (int i = 0; i < n; i ++) {
		a[i] = (n - i) * x;
		sumk += n - i;
		if (sumk >= k) x += y * (sumk / k), sumk %= k;
		
		t += a[i];
		//std::cout << t << "\n";
		if (t >= T) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
}