#include <bits/stdc++.h>
using namespace std;

long long dp[100] = {0, 1};

int main() {
	for (int i = 2; i <= 30; i++) dp[i] = (1 << i) - dp[i - 1];
	int n, t;
	cin >> n;
	while (n --) {
		cin >> t;
		cout << dp[t] << endl;
	}
}