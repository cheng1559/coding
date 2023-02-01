#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	ll n, m;
	std::cin >> n >> m;
	if (n >= 60) {
		std::cout << -1 << "\n";
		return 0;
	}
	vll a(n + 1), b(n + 1);
	ll sum = 1ll << n - 1;
	
	if (sum > m) {
		std::cout << -1 << "\n";
		return 0;
	}
	
	ll re = m - sum;
	
	// std::cout << re << "\n";
	
	a[1] = b[1] = 1;
	for (int i = 2; i <= n; i ++) a[i] = b[i] = 1ll << i - 2;
	
	for (int i = 1; i <= n && re > 0; i ++) {
		ll k = re / (1ll << n - i);
		// std::cout << k << "\n";
		re -= k * (1ll << n - i);
		for (int j = i; j <= n; j ++) a[j] += k * b[j - i + 1];
	}
	if (re > 0) a[n] += re;
	for (int i = 1; i <= n; i ++) std::cout << a[i] << " ";
}