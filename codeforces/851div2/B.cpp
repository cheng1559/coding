#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	ll n;
	std::cin >> n;
	ll x = 0, y = 0, ad = 1, t = 1;
	while (n) {
		int k = n % 10;
		x += k / 2 * t;
		y += k / 2 * t;
		if (k & 1) {
			x += !ad * t;
			y += ad * t;
			ad = !ad;
		}
		t *= 10;
		n /= 10;
	}
	std::cout << x << " " << y << "\n";
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