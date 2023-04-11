#include <bits/stdc++.h>
using namespace std;

const int M = 1000005;
int dp[15][M], k[15][M];
int n, x, t, maxt;

int main() {
	while (scanf("%d", &n), n) {
		memset(dp, 0, sizeof dp);
		memset(k, 0, sizeof k);
		maxt = 0;
		while (n --) {
			scanf("%d%d", &x, &t);
			k[x][t] ++;
			maxt = max(maxt, t);
		}
		for (int i = 0; i <= 10; i++) dp[i][maxt] = k[i][maxt];
		for (int tt = maxt - 1; tt >= 0; tt--) {
			for (int i = 0; i <= 10; i++) {
				int mm = 0;
				if (i == 0) mm = max(dp[i][tt + 1], dp[i + 1][tt + 1]);
				else if (i == 10) mm = max(dp[i][tt + 1], dp[i - 1][tt + 1]);
				else mm = max({dp[i][tt + 1], dp[i - 1][tt + 1], dp[i + 1][tt + 1]});
				dp[i][tt] = k[i][tt] + mm; 
			}
		}
		printf("%d\n", dp[5][0]);
	}
}