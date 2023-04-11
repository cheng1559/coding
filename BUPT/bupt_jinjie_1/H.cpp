#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;

ll M = 1e9 + 7;

struct matrix {
	vvll m;
	int size_x = 0, size_y = 0;
	
	matrix(vvll _m): m(_m) {size_y = m.size(), size_x = m[0].size();}
	
	matrix() {}
	
	matrix(int y, int x): size_x(x), size_y(y){
		m.resize(size_y, vll(size_x, 0));
	}
	
	matrix(int _size, bool i = false): size_x(_size), size_y(_size) {
		m.resize(size_y, vll(size_x, 0));
		if (i) for (int j = 0; j < size_y; j ++) set(j, j, 1);
	}
	
	inline ll at(int i, int j) const {return m[i][j];}
	inline void set(int i, int j, ll t) {m[i][j] = t;}
	
	matrix operator*(const matrix &b) const {
		if (this->size_x != b.size_y) {cout << "error" << endl; return {};}
		int x = b.size_x;
		int y = this->size_y;
		matrix tmp(y, x);
		for (int i = 0; i < y; i ++) {
			for (int j = 0; j < x; j ++) {
				ll sum = 0;
				for (int p = 0; p < this->size_x; p ++) sum = (sum + this->at(i, p) * b.at(p, j) % M) % M;
				tmp.set(i, j, sum);
			}
		}
		return tmp;
	}
	
	matrix operator^(ll n) const {
		if (this->size_y != this->size_x) {cout << "error" << endl; return {};}
		matrix ans(this->size_y, true);
		matrix a(*this);
		while (n) {
			if (n & 1) ans = ans * a;
			n >>= 1, a = a * a;
		}
		return ans;
	}
	
	void print() {
		for (int i = 0; i < size_y; i ++) {
			for (int j = 0; j < size_x; j ++) {
				cout << at(i, j) << " ";
			}
			cout << endl;
		}
	}
};
using mt = matrix;

int k, t;
int main() {
	mt b(10, 1);
	for (int i = 0; i < 10; i ++) b.set(i, 0, 9 - i);
	while (cin >> k >> M) {
		mt a(10);
		for (int i = 0; i < 10; i ++) cin >> t, a.set(0, i, t);
		for (int i = 1; i < 10; i ++) a.set(i, i - 1, 1);
		a = a ^ (k - 9);
		cout << (a * b).at(0, 0) << endl;
	}
}