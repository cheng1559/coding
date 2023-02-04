#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int f(int x) {
	int ans = 0;
	while (x) ans += x & 1, x >>= 1;
	return ans;
}


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n, q;
	std::cin >> n >> q;
	vi a(n);
	std::priority_queue<int> pq;
	for (int i = 0; i < n; i ++) std::cin >> a[i], pq.push(a[i]);
	vi p;
	while (pq.top() != 1) {
		int r = pq.top();
		p.push_back(r);
		pq.pop();
		pq.push(f(r));
	}
	p.push_back(pq.top());
	
	while (q --) {
		int k;
		std::cin >> k;
		std::cout << p[std::min(k, int(p.size() - 1))] << "\n";
	}
}