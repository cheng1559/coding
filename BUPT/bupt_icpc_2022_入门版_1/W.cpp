#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100] = {0, 1, 3};

int main() {
	int n, t;
	cin >> n;
	for (int i = 3; i <= 30; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}
	while (n --) {
		cin >> t;
		cout << dp[t] << endl;
	}
}