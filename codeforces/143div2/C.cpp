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
	vll a(n + 1), b(n + 1), ans(n + 1), sb(n + 1);
	vll mul(n + 2);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		std::cin >> b[i];
		sb[i] = sb[i - 1] + b[i];
	}

	for (int i = 1; i <= n; i ++) {
		int k = std::upper_bound(sb.begin() + i, sb.end(), a[i] + sb[i - 1]) - sb.begin();
		int sum = sb[k - 1] - sb[i - 1];
		if (k <= n) {
			ans[k] += a[i] - sum;
		}
		mul[i] ++, mul[k] --;
	}
	
	for (int i = 1, r = 0; i <= n; i ++) {
		r += mul[i];
		ans[i] += b[i] * r;
	}
	
	for (int i = 1; i <= n; i ++) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
	
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