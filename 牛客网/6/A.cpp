#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


std::string t[] = {"very esay", "easy", "medium", "hard", "very hard", "can not imagine"};

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	ll x, i = 0;
	std::cin >> x;
	
	i += (x > 7) + (x > 233) + (x > 10032) + (x > 114514) + (x > 1919810);
	std::cout << t[i] << "\n";
}