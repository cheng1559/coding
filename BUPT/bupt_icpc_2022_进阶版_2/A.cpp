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
		data[root].val = data[root << 1].val + data[root << 1 | 1].val;
	}
	
	inline void down(int root) {
		unit &t = data[root];
		unit &tl = data[root << 1], &tr = data[root << 1 | 1];
		int leftlen = tl.right - tl.left + 1;
		int rightlen = tr.right - tr.left + 1;
		if (t.lazy) {
			/*--------------------*/
			tl.lazy = t.lazy;
			tr.lazy = t.lazy;
			tl.val = t.lazy * leftlen;
			tr.val = t.lazy * rightlen;
			t.lazy = 0;
			/*--------------------*/
		}
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
		down(root);
		T answer = 0;
		if (Left <= mid) answer += query(Left, Right, root << 1);
		if (Right > mid) answer += query(Left, Right, root << 1 | 1);
		return answer;
	}
	
	void update(int Left, int Right, T val, int root=1) {
		unit &t = data[root];
		int left = t.left, right = t.right;
		if (Left <= left && Right >= right) {
			/*--------------------*/
			t.val = val * (right - left + 1);
			t.lazy = val;
			/*--------------------*/
			return;
		}
		int mid = left + right >> 1;
		down(root);
		if (Left <= mid) update(Left, Right, val, root << 1);
		if (Right > mid) update(Left, Right, val, root << 1 | 1);
		up(root);
	}

	SegmentTree(vector<T> &_a):a(_a) {
		size = a.size() - 1;
		data.resize(size << 2);
		build(1, size);
	}
};

using sg = SegmentTree<int>;

void solve() {
	int n, q;
	cin >> n >> q;
	vi a(n + 1, 1);
	sg t(a);
	while (q --) {
		int l, r, k;
		cin >> l >> r >> k;
		t.update(l, r, k);
	}
	cout << t.query(1, n) << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) solve();
}