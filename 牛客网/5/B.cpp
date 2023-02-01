#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	if (n % 2) std::cout << "Yaya-win!" << "\n";
	else std::cout << "win-win!" << "\n";
}