#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	int n;
	ll ans = 0;
	std::cin >> n;
	vi a(n), cnt(n + 1);
	for (int i = 0; i < n; i ++) std::cin >> a[i], cnt[a[i]] ++;
	std::sort(a.begin(), a.end());
	for (int i = 1, j = 0; j < n && i <= n; i ++) {
		if (!cnt[i]) {
			while (a[j] < i) j ++;
			if (j < n) {
				ans += a[j] - i;
				cnt[a[j]] --;
				j ++;
			}
		}
	}
	std::cout << ans << "\n";
	
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) solve();
}