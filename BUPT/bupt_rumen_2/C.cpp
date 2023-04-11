#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7fffffff, M = 2005;
int arr[M], n, k;
int dp[M][M];

int f(int a, int b) {return (b - a) * (b - a);}

int main() {
	while (~scanf("%d %d", &n, &k)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", arr + i);
		}
		sort(arr + 1, arr + n + 1);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= k; j ++) {
				dp[i][j] = inf;
			}
		}
		for (int i = 2; i <= n; i ++) {
			for (int j = 1; 2 * j <= i; j ++) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + f(arr[i], arr[i - 1]));
			}
		}
		printf("%d\n", dp[n][k]);
	}
}