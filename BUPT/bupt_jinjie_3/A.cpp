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
		vi e[n + 1], in(n + 1), ans;
		while (m --) {
			int a, b;
			std::cin >> a >> b;
			e[a].push_back(b);
			in[b] ++;
		}
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
		for (int i = 1; i <= n; i ++) {
			if (!in[i]) {
				pq.push(i);
			}
		}
		while (pq.size()) {
			int tmp = pq.top();
			ans.push_back(tmp);
			pq.pop();
			for (auto i : e[tmp]) {
				in[i] --;
				if (!in[i]) {
					pq.push(i);
				}
			}
		}
		for (auto i : ans) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	
}