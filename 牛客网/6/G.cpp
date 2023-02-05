#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	vll a(n), b;
	ll ans = 0;
	for (int i = 0; i < n; i ++) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	
	for (int i = 0; i < n / 2; i += 2) b.push_back(a[i] * a[i + 1]);
	for (int i = n - 1; i > n / 2; i -= 2) b.push_back(a[i] * a[i - 1]);
	std::sort(b.begin(), b.end(), [](int a, int b) { return a > b; });
	for (int i = 0; i < k; i ++) ans += b[i];
	std::cout << ans << "\n";
}