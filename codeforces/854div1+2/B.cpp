#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

struct node {
	int v, id;
	bool operator< (node a, node b) {
		return a.v < b.v;
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b;
	for (int i = 0; i < n; i ++) {
		std::cin >> a[i];
	}
	if (std::count(a.begin(), a.end(), a[0]) == n) {
		std::cout << 0 << "\n";
		return;
	}
	if (std::count(a.begin(), a.end(), 1)) {
		std::cout << -1 << "\n";
		return;
	}
	
	std::vector<pii> ans;
	
	
	while (a[p] != 2) {
		if (a[0] > a[i]) {
			a[0] = (a[0] + a[i] - 1) / a[0];
			ans.push_back({1, i + 1});
		} else {
			a[i] = (a[i] + a[0] - 1) / a[i];
			ans.push_back({i + 1, 1});
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (i == p) continue;
		while (a[i] != 2) {
			a[i] = (a[i] - 1) / 2 + 1;
			ans.push_back({i + 1, 1});
		}
	}
	
	
	
	std::cout << ans.size() << "\n";
	for (auto i : ans) {
		std::cout << i.first << " " << i.second << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	//std::cout << std::fixed << std::setprecision(2);
	int T;
	std::cin >> T;
	while (T --) {
		solve();
	}
}