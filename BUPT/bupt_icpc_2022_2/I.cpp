#include <bits/stdc++.h>
using namespace std;

int dp[10005], c[] = {0, 150, 200, 350}, T, N;

int main() {
	cin >> T;
	while (T --) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 1; i <= 3; i ++) {
			for (int j = c[i]; j <= N; j ++) {
				dp[j] = max(dp[j], dp[j - c[i]] + c[i]);
			}
		}
		cout << N - dp[N] << endl;
	}
}