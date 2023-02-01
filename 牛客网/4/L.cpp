#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	ll a, b, c, la, lb, lc;
	std::cin >> a >> b >> c;
	ll sum = a + b + c;
	if (sum & 1) {
		std::cout << "No" << "\n";
		return;
	}
	la = (sum >> 1) - a;
	lb = (sum >> 1) - b;
	lc = (sum >> 1) - c;
	vll s = {la, lb, lc};
	std::sort(s.begin(), s.end());
	if (s[0] + s[1] <= s[2]) {
		std::cout << "No" << "\n";
	}
	else {
		std::cout << "Yes" << "\n";
		std::cout << la << " " << lb << " " << lc << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}