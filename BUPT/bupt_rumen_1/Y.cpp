#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100] = {0, 1, 2, 2};

int main() {
	int n;
	for (int i = 4; i <= 50; i++) dp[i] = dp[i - 1] + 2 * dp[i - 2];
	while (cin >> n) cout << dp[n] * 3 << endl;
}