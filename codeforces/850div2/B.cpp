#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n, w, h;
	std::cin >> n >> w >> h;
	vi a(n), b(n);
	std::vector<pii> c(n);
	for (int i = 0; i < n; i ++) std::cin >> a[i];
	for (int i = 0; i < n; i ++) std::cin >> b[i];
	for (int i = 0; i < n; i ++) c[i] = {a[i] - b[i], i};
	sort(c.begin(), c.end(), [](pii a, pii b) { return a.first > b.first; });
	
	int k = a[c.front().second] - b[c.front().second] + a[c.back().second] - b[c.back().second] >> 1;
	for (auto &i : a) i -= k;
	
	for (int i = 0; i < n; i ++) {
		if (a[i] - w > b[i] - h || a[i] + w < b[i] + h) {
			std::cout << "No" << "\n";
			return;
		}
	}
	std::cout << "Yes" << "\n";
	
	
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}