#include <bits/stdc++.h>
using namespace std;

long long dp[100] = {0, 1, 2};

int main() {
	int t;
	for (int i = 3; i <= 50; i++) dp[i] = dp[i - 1] + dp[i - 2];
	while (cin >> t) cout << dp[t] << endl;
}