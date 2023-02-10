#include <bits/stdc++.h>


template<typename T>
class BIT {
private:
	int n;
	std::vector<T> t;
	int lowbit(int x) const { return x & -x; }
	
	void update(int k, T val) {
		for (int i = k; i <= n; i += lowbit(i)) {
			t[i] += val;
		}
	}
	
	T sum(int k) {
		T ans = 0;
		for (int i = k; i > 0; i -= lowbit(i)) {
			ans += t[i];
		}
		return ans;
	}

public:
	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	
	BIT(std::vector<T> &a) {
		n = a.size() - 1;
		t.resize(n + 1);
		for (int i = 1; i <= n; i ++) {
			update(i, a[i]);
		}
	}
};





template<typename T>
class range_BIT {
private:
	int n;
	std::vector<T> t;
	int lowbit(int x) const { return x & -x; }
	
	void update(int k, T val) {
		for (int i = k; i <= n; i += lowbit(i)) {
			t[i] += val;
		}
	}
	
	T sum(int k) {
		T ans = 0;
		for (int i = k; i > 0; i -= lowbit(i)) {
			ans += t[i];
		}
		return ans;
	}
	
public:
	void update(int l, int r, T val) {
		update(r + 1, -val);
		update(l, val);
	}
	
	T query(int k) {
		return sum(k);
	}
	
	range_BIT(std::vector<T> &a) {
		a[0] = 0;
		n = a.size() - 1;
		t.resize(n + 1);
		for (int i = 1; i <= n; i ++) {
			update(i, a[i] - a[i - 1]);
		}
	}
};




template<typename T>
class srange_BIT {
private:
	int n;
	std::vector<T> t1, t2;
	int lowbit(int x) const { return x & -x; }
	
	void update(int k, T val) {
		for (int i = k; i <= n; i += lowbit(i)) {
			t1[i] += val;
			t2[i] += val * k;
		}
	}
	
	T sum(int k) {
		T p1 = 0, p2 = 0;
		for (int i = k; i > 0; i -= lowbit(i)) {
			p1 += t1[i];
			p2 += t2[i];
		}
		return (k + 1) * p1 - p2;
	}
	
public:
	void update(int l, int r, T val) {
		update(r + 1, -val);
		update(l, val);
	}
	
	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	
	srange_BIT(std::vector<T> &a) {
		a[0] = 0;
		n = a.size() - 1;
		t1.resize(n + 1);
		t2.resize(n + 1);
		for (int i = 1; i <= n; i ++) {
			update(i, a[i] - a[i - 1]);
		}
	}
};