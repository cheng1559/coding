#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int lowbit(int x) { return x & -x; }

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	while (std::cin >> n, n) {
		std::cout << lowbit(n) << "\n";
	}
}