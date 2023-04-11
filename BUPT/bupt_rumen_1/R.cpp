#include <bits/stdc++.h>
using namespace std;

long long dp[100] = {0, 1, 1};

int main() {
	int n, t;
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cin >> n;
	while (n --) {
		cin >> t;
		cout << dp[t] << endl;
	}
}