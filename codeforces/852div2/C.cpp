#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	vi a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	int max = n, min = 1;
	int i = 1, j = n;
	while (i < j) {
		if (a[i] == max) i ++, max --;
		else if (a[i] == min) i ++, min ++;
		else if (a[j] == max) j --, max --;
		else if (a[j] == min) j --, min ++;
		else {
			std::cout << i << " " << j << "\n";
			return;
		}
	}
	std::cout << -1 << "\n";
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
}