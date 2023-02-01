#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

template<typename T>
class SegmentTree {
private:
	struct unit {
		T val = 0;
		T lazy = 0;
		int left;
		int right;
	};
	vector<unit> data;
	vector<T> a;
	
	size_t size;
	
	inline void up(int root) {
		data[root].val = max(data[root << 1].val, data[root << 1 | 1].val);
	}
	
	void build(int left, int right, int root=1) {
		unit &t = data[root];
		t.left = left, t.right = right;
		if (left == right) {
			t.val = a[left];
			return;
		}
		int mid = left + right >> 1;
		build(left, mid, root << 1);
		build(mid + 1, right, root << 1 | 1);
		up(root);
	}
	
public:
	T query(int Left, int Right, int root=1) {
		unit &t = data[root];
		int left = t.left, right = t.right;
		if (Left <= left && Right >= right) return t.val;
		if (Left > right || Right < left) return 0;
		int mid = left + right >> 1;
		T ans = 0;
		if (Left <= mid) ans = max(ans, query(Left, Right, root << 1));
		if (Right > mid) ans = max(ans, query(Left, Right, root << 1 | 1));
		return ans;
	}
	
	void update(int node, T val, int root=1) {
		unit &t = data[root];
		int left = t.left, right = t.right;
		if (left == right) {
			t.val = val;
			return;
		}
		int mid = left + right >> 1;
		if (node <= mid) update(node, val, root << 1);
		else update(node, val, root << 1 | 1);
		up(root);
	}

	SegmentTree(vector<T> &_a):a(_a) {
		size = a.size() - 1;
		data.resize(size << 2);
		build(1, size);
	}
};

using sg = SegmentTree<int>;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		vi a(n + 1);
		for (int i = 1; i <= n; i ++) cin >> a[i];
		sg t(a);
		while (m --) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'Q') cout << t.query(a, b) << "\n";
			else t.update(a, b);
		}
	}
}