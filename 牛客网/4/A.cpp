#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int x, y;
	std::cin >> x >> y;
	
	if (x == 2 && y == 3) std::cout << 3;
	else if (x == 3 && y == 2) std::cout << 3;
	else std::cout << std::min(x, y) << "\n";
}