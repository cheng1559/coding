#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	vi a(n);
	for (int i = 0; i < n; i ++) std::cin >> a[i];
	for (int i = 1; i < n; i ++) {
		if (a[i] + a[i - 1] == -2) {
			std::cout << std::accumulate(a.begin(), a.end(), 0) + 4 << "\n";
			return;
		}
	}
	for (int i = 1; i < n; i ++) {
		if (a[i] + a[i - 1] == 0) {
			std::cout << std::accumulate(a.begin(), a.end(), 0) << "\n";
			return;
		}
	}
	std::cout << std::accumulate(a.begin(), a.end(), 0) - 4 << "\n";
	
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t -- ) solve();
}