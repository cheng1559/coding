#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

struct e {int from, to; double val;};

const int INF = 0x7fffffff;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m, cnt = 1;
	while (std::cin >> n, n) {
		std::unordered_map<std::string, int> ump;
		std::vector<e> g;
		for (int i = 0; i < n; i ++) {
			std::string s;
			std::cin >> s;
			ump[s] = i;
		}
		std::cin >> m;
		for (int i = 0; i < m; i ++) {
			std::string a, b;
			double k;
			std::cin >> a >> k >> b;
			g.push_back({ump[a], ump[b], k});
		}
		
		int flag = 0;
		
		auto bf = [&](int s) {
			std::vector<double> dis(n, 1e9);
			dis[s] = 1;
			for (int k = 0; k < n - 1; k ++) {
				for (auto i : g) {
					if (dis[i.from] * i.val > dis[i.to]) {
						dis[i.to] = dis[i.from] * i.val;
					}
				}
			}
			for (auto i : g) {
				if (dis[i.from] * i.val > dis[i.to]) {
					return true;
				}
			}
			return false;
		};
		
		for (int i = 0; i < n; i ++) {
			if (bf(i)) {
				flag = 1;
				break;
			}
		}
		std::cout << "Case" << cnt ++ << ": " << (flag ? "Yes" : "No") << "\n";
	}
}