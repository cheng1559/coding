#include <bits/stdc++.h>
using namespace std;

int s[205];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		memset(s, 0, sizeof s);
		while (n --) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a > b) swap(a, b);
			s[(a + 1) / 2] ++;
			s[(b + 1) / 2 + 1] --;
		}
		int ans = 0, sum = 0;
		for (int i = 1; i <= 200; i++) {
			sum += s[i];
			ans = max(ans, sum);
		}
		printf("%d\n", ans * 10);
	}
}