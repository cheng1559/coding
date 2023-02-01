#include <bits/stdc++.h>
using namespace std;

const int MOD = 10;

int qpow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n % 2) ans = ans * a % MOD;
		a = a * a % MOD;
		n /= 2;
	}
	return ans;
}

int main() {
	int t, n;
	cin >> t;
	while (t --) {
		cin >> n;
		cout << qpow(n % 10, n) << endl;
	}
}