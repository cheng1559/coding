#include <bits/stdc++.h>
using namespace std;

const int M = 10005;
int k, s[M], sg[M], m, n, ans, t;
bool vis[M];

void SG() {
	for (int i = 0; i <= 10000; i ++) {
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < k; j ++) if (i - s[j] >= 0) vis[sg[i - s[j]]] = true;
		int k = 0;
		while (vis[k]) k ++;
		sg[i] = k;
	}
}

int main() {
	while (scanf("%d", &k), k) {
		for (int i = 0; i < k; i ++) scanf("%d", s + i);
		SG();
		scanf("%d", &m);
		while (m --) {
			ans = 0;
			scanf("%d", &n);
			while (n --) {
				scanf("%d", &t);
				ans ^= sg[t];
			}
			putchar(ans ? 'W' : 'L');
		}
		putchar('\n');
	}
}