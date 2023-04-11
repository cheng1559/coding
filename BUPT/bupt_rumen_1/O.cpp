#include <bits/stdc++.h>
using namespace std;

struct side {int a, b, len;} l[100007];

int s[100007], ss[100007];

int find(int x, int s[]) {
	int r = x;
	while (r != s[r]) r = s[r];
	return r;
}

void merge(int a, int b, int s[]) {
	s[find(a, s)] = find(b, s);
}

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n), m) {
		for (int i = 1; i <= n; i++) s[i] = i, ss[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &l[i].a, &l[i].b, &l[i].len);
			merge(l[i].a, l[i].b, s);
		}
		
		int cnt = -1;
		for (int i = 1; i <= n; i++) cnt += s[i] == i;
		if (cnt) {
			printf("?\n");
			continue;
		}
		
		sort(l, l + m, [](side a, side b) {return a.len < b.len;});
		
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (find(l[i].a, ss) == find(l[i].b, ss)) continue;
			merge(l[i].a, l[i].b, ss);
			ans += l[i].len;
		}
		printf("%d\n", ans);
	}
}