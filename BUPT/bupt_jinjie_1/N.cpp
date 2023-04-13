#include <bits/stdc++.h>

using i64 = long long;

int kmpFind(std::string s, std::string t) {
	int n = s.length(), m = t.length();
	std::vector<int> ne(m + 1);
	for (int i = 1, j = 0; i < m; ++i) {
		while (j > 0 && t[i] != t[j]) { j = ne[j]; }
		if (t[i] == t[j]) { ++j; }
		 ne[i + 1] = j;
	}
	for (int i = 0, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != t[j]) { j = ne[j]; }
		if (s[i] == t[j]) { ++j; }
		if (j == m) { return i - m + 1; }
	}
	return -1;
}

int kmpCount(std::string s, std::string t) {
	int n = s.length(), m = t.length(), cnt = 0;
	std::vector<int> ne(m + 1);
	for (int i = 1, j = 0; i < m; ++i) {
		while (j > 0 && t[i] != t[j]) { j = ne[j]; }
		if (t[i] == t[j]) { ++j; }
		 ne[i + 1] = j;
	}
	for (int i = 0, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != t[j]) { j = ne[j]; }
		if (s[i] == t[j]) { ++j; }
		if (j == m) {
			++cnt;
			j = 0;
		}
	}
	return cnt;
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	std::string s, t;
	while (std::cin >> s, s != "#") {
		std::cin >> t;
		std::cout << kmpCount(s, t) << "\n";
	}
}