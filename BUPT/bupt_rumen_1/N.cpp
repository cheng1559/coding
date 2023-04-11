#include <bits/stdc++.h>
using namespace std;

struct side {int a, b, len;} l[100007];
int nn;

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
	int m, n, nn;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; i++) s[i] = i;
		
		nn = n * (n - 1) >> 1;
		for (int i = 0; i < nn; i++) 
			scanf("%d %d %d", &l[i].a, &l[i].b, &l[i].len);
		sort(l, l + nn, [](side a, side b) {return a.len < b.len;});
		
		int ans = 0;
		for (int i = 0; i < nn; i++) {
			if (find(l[i].a) == find(l[i].b)) continue;
			merge(l[i].a, l[i].b);
			ans += l[i].len;
		}
		printf("%d\n", ans);
	}
}