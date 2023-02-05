#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int x, a, b;
	std::cin >> x >> a >> b;
	std::cout << std::fixed << std::setprecision(9) 
	<< std::min(std::max(0.0, 1.0 * (x - a) / (b - a + 1)), 1.0) << "\n";
}