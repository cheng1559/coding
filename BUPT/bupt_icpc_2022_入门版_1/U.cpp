#include <bits/stdc++.h>
using namespace std;

long long dp[10005] = {0, 2, 7};

int main() {
	int n, t;
	for (int i = 3; i <= 10000; i++) {
		dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) + 4;
	}
	cin >> n;
	while (n --) {
		cin >> t;
		cout << dp[t] << endl;
	}
}