#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000;

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
	int a, b;
	while (1) {
		cin >> a >> b;
		if (!a && !b) break;
		cout << qpow(a, b) << endl;
	}
}