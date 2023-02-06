#include <bits/stdc++.h>

template<typename T>
std::vector<int> discretize(std::vector<T> &a) {
	int n = a.size();
	auto b = a;
	std::vector<int> c(n);
	std::sort(b.begin(), b.end());
	int size = std::unique(b.begin(), b.end()) - b.begin();
	for (int i = 0; i < n; i ++) {
		c[i] = std::lower_bound(b.begin(), b.begin() + size, a[i]) - b.begin() + 1;
	}
	return c;
}