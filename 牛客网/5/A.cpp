#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, x, k, q;
	std::cin >> n >> q;
	vll a(n + 1), ar(n + 1);
	
	for (int i = 1; i <= n; i ++) std::cin >> a[i];
	sort(a.begin() + 1, a.end());

	for (int i = 1; i <= n; i ++) ar[i] = ar[i - 1] + a[i];
	
	
	while (q --) {
		std::cin >> k >> x;
		int d, l = 1, r = n;
		if (a[l] > x) d = 0;
		else if (a[r] <= x) d = n;
		else {
			while (l <= r) {
				int mid = l + r >> 1;
				if (a[mid] <= x && (mid == n || a[mid + 1] > x)) {
					d = mid;
					break;
				}
				if (a[mid] > x) r = mid - 1;
				else l = mid + 1, d = mid;
			}
		}
		std::cout << ar[d] - ar[std::max(d - k, 0)] << "\n";
	}
}