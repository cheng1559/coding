#include <bits/stdc++.h>


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	//std::cout << std::fixed << std::setprecision(2);
	int n;
	std::cin >> n;
	
	std::vector<int> c(n), l(n << 1), r(n << 1);
	std::vector<std::string> v(n);
	
	for (int i = 0; i < n; i ++) {
		std::cin >> v[i];
	}
	
	int ans = 0;
	
	auto dfs = [&](auto dfs, int k) {
		if (k == n) {
			ans ++;
			return;
		}
		for (int i = 0; i < n; i ++) {
			if (v[k][i] == '.') continue;
			if (!c[i] && !l[k + i] && !r[k - i + n]) {
				c[i] = 1, l[k + i] = 1, r[k - i + n] = 1;
				dfs(dfs, k + 1);
				c[i] = 0, l[k + i] = 0, r[k - i + n] = 0;
			}
		}
	};
	
	dfs(dfs, 0);
	std::cout << ans << "\n";
}