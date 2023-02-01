#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100] = {0, 3, 8};

int main() {
	int n;
	for (int i = 3; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2] << 1;
	while (cin >> n) cout << dp[n] << endl;
}