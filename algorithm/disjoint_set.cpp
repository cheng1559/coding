#include <bits/stdc++.h>


class DSU {
public:
	std::vector<int> uset, rank;
	int find(int x) {
		if (x != uset[x]) uset[x] = find(uset[x]);
		return uset[x];
	}
	void merge(int x, int y) {
		if ((x = find(x)) == (y = find(y))) return;
		if (rank[x] > rank[y]) uset[y] = x;
		else {
			uset[x] = y;
			if (rank[x] == rank[y]) rank[y] ++;
		}
	}
	DSU(int n) {
		uset.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i ++) uset[i] = i;
	}
};
