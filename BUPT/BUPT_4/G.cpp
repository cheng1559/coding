#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;

const ll M = 9973;

struct matrix {
	vvll m;
	int size = 0;
	
	matrix(vvll _m): m(_m) {size = m.size();}
	
	matrix() {}
	
	matrix(int _size, bool i = false): size(_size) {
		m.resize(size, vll(size, 0));
		if (i) for (int j = 0; j < size; j ++) set(j, j, 1);
	}
	
	inline ll at(int i, int j) const {return m[i][j];}
	inline void set(int i, int j, ll t) {m[i][j] = t;}
	
	void resize(int _size) {
		size = _size;
		m.resize(size, vll(size, 0));
	}
	
	matrix operator*(const matrix &b) const {
		int n = this->size;
		matrix tmp(n);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				ll sum = 0;
				for (int p = 0; p < n; p ++) sum += this->at(i, p) * b.at(p, j) % M;
				tmp.set(i, j, sum);
			}
		}
		return tmp;
	}
	
	matrix operator^(ll n) const {
		matrix ans(this->size, true);
		matrix a(*this);
		while (n) {
			if (n & 1) ans = ans * a;
			n >>= 1, a = a * a;
		}
		return ans;
	}
};

using mt = matrix;

int n, k, T, ans;
int main() {
	cin >> T;
	while (T --) {
		cin >> n >> k;
		ans = 0;
		mt a(n);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				int t;
				cin >> t;
				a.set(i, j, t);
			}
		}
		a = a ^ k;
		for (int i = 0; i < n; i ++) ans = (ans + a.at(i, i)) % M;
		cout << ans << endl;
	}
}