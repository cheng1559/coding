#include <bits/stdc++.h>
using namespace std;

const int n = 100007;
int s[n], vis[n];

int find(int x) {
	int r = x;
	while (r != s[r]) r = s[r];
	return r;
}

void merge(int a, int b) {
	s[find(a)] = find(b);
}

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b), a != -1 && b != -1) {
		bool flag = true;
		for (int i = 1; i <= n; i++) s[i] = i;
		memset(vis, 0, sizeof vis);
		if (!a && !b) {
			printf("Yes\n");
			continue;
		}
		while (a && b) {
			vis[a] = vis[b] = 1;
			if (find(a) == find(b)) flag = false; //有无重复边
			merge(a, b);
			scanf("%d%d", &a, &b);
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) if (vis[s[i]] && s[i] == i) ans ++; // 是否连通
		if (ans == 0 && flag) printf("Yes\n");
		else printf("No\n");
	}	
}