#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	ll n;
	ll ans = 0;
	std::cin >> n;
	while (n > 2) {
		n -= (n) / 2;
		ans ++;
	}
	std::cout << ans << "\n";
}