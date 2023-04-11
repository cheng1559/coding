#include <bits/stdc++.h>
using namespace std;

int tmp[10], n, idx;

void dfs(int m, int cur) {
	if (m == n) {
		for (int i = 0; i < n; i ++) printf("%d ", tmp[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i ++) {
		int flag = 0;
		for (int k = 0; k < idx; k ++) if (i == tmp[k]) flag = 1;
		if (flag) continue;
		tmp[idx ++] = i;
		dfs(m + 1, i);
		idx --;
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		dfs(0, 1);
	}
}