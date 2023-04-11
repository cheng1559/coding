#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

struct e {int to, val;};

struct node {int id, dis;};

const ll INF = 1ll << 31;

void solve() {
	int n, q;
	std::cin >> n;
	vi v(n + 1), vis(n + 1);
	std::vector<e> g[n + 1];
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> v[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		int a, b;
		std::cin >> a >> b;
		e[a].push_back({b, 1});
		e[b].push_back({a, 1});
	}
	
	std::cin >> q;
	ll ans = 0;
	
	auto op1 = [&](int a, int b) {
		
	};
	
	auto op2 = [&](int a) {
		
	};
	
	auto op3 = [&](int a) {
		
	};
	
	while (q --) {
		int op, a, b;
		std::cin >> op;
		if (op == 1) {
			std::cin >> a >> b;
			op1(a, b);
		} else if (op == 2) {
			std::cin >> a;
			op2(a);
		} else {
			std::cin >> a;
			op3(a);
		}
		
		ll ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) ans += v[i];
		}
		std::cout << ans << "\n";
	}
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