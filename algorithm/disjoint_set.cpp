#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;


class disjoint_set {
public:
	vi uset, rank;
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
	disjoint_set(int n) {
		uset.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i ++) uset[i] = i;
	}
};

using dsu = disjoint_set;