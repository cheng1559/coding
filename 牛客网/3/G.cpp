#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

inline ll qpow(ll a, ll n, ll M) {
	if (a <= 0 || n <= 0) return -1;
	ll ans = 1;
	while (n) {
		a %= M;
		if (n & 1) ans = ans * a % M;
		n >>= 1, a = a * a;
	}
	return ans;
}

vi num, op;
ll eq;
bool flag = false;

bool eval() {
	ll res = num[0];
	for (int i = 0; i < op.size(); i ++) {
		if (op[i] == 0) res = res + num[i + 1];
		else if (op[i] == 1) res = res - num[i + 1];
		else {
			res = qpow(res, res, num[i + 1]);
			if (res == -1) return false;
		}
	}
	return res == eq;
}

void dfs() {
	if (flag) return;
	if (op.size() == num.size() - 1) {
		if (eval()) {
			for (int i = 0; i < op.size(); i ++) {
				cout << num[i] << "+-#"[op[i]];
			}
			cout << num.back() << "=" << eq << "\n";
			flag = true;
		}
		return;
	}
	
	for (int i = 0; i < 3; i ++) {
		op.push_back(i);
		dfs();
		op.pop_back();
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll tmp = 0;
	for (auto i : s) {
		if (!isdigit(i)) num.push_back(tmp), tmp = 0;
		else tmp = tmp * 10 + i - '0';
	}
	eq = tmp;
	dfs();
	if (!flag) cout << -1 << "\n";
}