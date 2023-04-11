#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;

const ll M = 123456789;

struct matrix {
	vvll m;
	int size_x = 0, size_y = 0;
	
	matrix(vvll _m): m(_m) {size_y = m.size(), size_x = m[0].size();}
	
	matrix() {}
	
	matrix(int y, int x): size_x(x), size_y(y) {m.resize(size_y, vll(size_x, 0));}
	
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
				for (int p = 0; p < this->size_x; p ++) sum += this->at(i, p) * b.at(p, j) % M, sum %= M;
				tmp.set(i, j, sum);
			}
		}
		return tmp;
	}
	
	matrix operator^(ll n) const {
		if (this->size_y != this->size_x) {cout << "error" << endl; return {};}
		matrix ans(this->size_y, this->size_x);
		for (int j = 0; j < size_y; j ++) ans.set(j, j, 1);
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

ll n;
int T;

int main() {
	vvll va = {
		{1, 2, 1, 3, 3, 1},
		{1, 0, 0, 0, 0, 0},
		{0, 0, 1, 3, 3, 1},
		{0, 0, 0, 1, 2, 1},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 1}
	};
	vvll vb = {{2}, {1}, {8}, {4}, {2}, {1}};
	mt a(va), b(vb);
	cin >> T;
	while (T --) {
		cin >> n;
		mt t = a ^ (n - 2);
		cout << (t * b).at(0, 0) << endl;
	}
}