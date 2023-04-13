#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> getNext(std::string s) {
	int n = s.length();
	std::vector<int> ne(n + 1);
	for (int i = 1, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != s[j]) { j = ne[j]; }
		if (s[i] == s[j]) { ++j; }
		 ne[i + 1] = j;
	}
	return ne;
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	std::string s, t;
	while (std::cin >> s >> t) {
		int n = s.length(), m = t.length();
		auto ne = getNext(s + t);
		int l = std::min({ ne[n + m], n, m });
		if (l != 0) { std::cout << s.substr(0, l) << " "; }
		std::cout << l << "\n";
	}
}