#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, m;
	while (std::cin >> n >> m) {
		vi e[n + 1], in(n + 1), ans(n + 1);
		while (m --) {
			int a, b;
			std::cin >> a >> b;
			e[b].push_back(a);
			in[a] ++;
		}
		std::queue<int> pq;
		for (int i = 1; i <= n; i ++) {
			if (!in[i]) {
				pq.push(i);
			}
		}
		int s = 888;
		while (pq.size()) {
			int r = pq.size();
			while (r --) {
				int tmp = pq.front();
				ans[tmp] = std::max(ans[tmp], s);
				pq.pop();
				for (auto i : e[tmp]) {
					in[i] --;
					if (!in[i]) {
						pq.push(i);
					}
				}
			}
			s ++;
		}
		int flag = 0;
		for (int i = 1; i <= n; i ++) {
			if (in[i]) {
				std::cout << -1 << "\n";
				flag = 1;
				break;
			}
		}
		if (!flag) {
			std::cout << accumulate(ans.begin() + 1, ans.end(), 0ll) << "\n";
		}
		
	}
}