#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

ll h[100004], v[100004];
int main() {
	std::cin.tie(0), std::cout.tie(0);
	ll n, t, a, ans = 0, ans2 = 0;
	std::cin >> n >> t >> a;
	for (int i = 0; i < n; i ++) {
		std::cin >> h[i] >> v[i];
	}
	for (int i = 0; i < n; i ++) {
		if (t * v[i] >= a && h[i] > a) {
			std::cout << -1 << "\n";
			return 0;
		}
		if (h[i] <= a) ans += t;
		else ans += ((h[i] - a - 1) / (a - v[i] * t) + 1) * t + t;
	}
	std::cout << ans - (t - 1) << "\n";
}