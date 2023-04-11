#include <bits/stdc++.h>
using namespace std;

int s[10007];

int find(int x) {
	int r = x;
	while (r != s[r]) r = s[r];
	return r;
}

void merge(int a, int b) {
	s[find(a)] = find(b);
}

int main() {
	int m, n, a, b;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; i++) s[i] = i;
		scanf("%d", &m);
		while (m --) {
			scanf("%d%d", &a, &b);
			merge(a, b);
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) ans += s[i] == i;
		printf("%d\n", ans);
	}	
}