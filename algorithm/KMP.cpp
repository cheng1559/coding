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

int kmpFind(std::string s, std::string t) {
	int n = s.length(), m = t.length();
	auto ne = getNext(t);
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
	auto ne = getNext(t);
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