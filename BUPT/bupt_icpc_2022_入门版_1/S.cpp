#include <bits/stdc++.h>
using namespace std;

long long dp[100] = {0, 1, 2};

int main() {
	int n, a, b;
	for (int i = 3; i <= 50; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cin >> n;
	while (n --) {
		cin >> a >> b;
		cout << dp[b - a] << endl;
	}
}