#include <bits/stdc++.h>
using namespace std;

struct st{int a, b; double c;} s[100007];

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n), m != -1 && n != -1) {
		double ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &s[i].a, &s[i].b);
			if (s[i].b == 0) s[i].c = 1e9; // 防止除0
			else s[i].c = 1.0 * s[i].a / s[i].b;
		}
		sort(s, s + n, [](st a, st b){return a.c > b.c;});
		for (int i = 0; i < n; i++) {
			if (m >= s[i].b) m -= s[i].b, ans += s[i].a;
			else {
				ans += 1.0 * m / s[i].b * s[i].a;
				break;
			}
		}
		printf("%.3f\n", ans + 1e-6);
	}
}


