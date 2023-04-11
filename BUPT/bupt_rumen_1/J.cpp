#include <bits/stdc++.h>
using namespace std;

struct in {int l, r;} s[107];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++) scanf("%d%d", &s[i].l, &s[i].r);
		sort(s, s + n, [] (in a, in b) {return a.r < b.r;});
		int ans = 1, m = s[0].r;
		for (int i = 1; i < n; i++) {
			if (s[i].l >= m) ans++, m = s[i].r;
		}
		printf("%d\n", ans);
	}
}