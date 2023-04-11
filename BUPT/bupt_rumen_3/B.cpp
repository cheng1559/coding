#include <bits/stdc++.h>
using namespace std;

int m, n, t, stx, sty, edx, edy;
bool flag = false;
char grid[10][10];

void dfs(int curt, int x, int y) {
	if (flag || grid[y][x] == 'X') return;
	grid[y][x] = 'X';
	if (curt >= t) {
		if (curt == t && x == edx && y == edy) flag = true;
		return;
	}
	if (x + 1 < n && grid[y][x + 1] != 'X') {
		dfs(curt + 1, x + 1, y);
		grid[y][x + 1] = '.';
	}
	if (x - 1 >= 0 && grid[y][x - 1] != 'X') {
		dfs(curt + 1, x - 1, y);
		grid[y][x - 1] = '.';
	}
	if (y + 1 < m && grid[y + 1][x] != 'X') {
		dfs(curt + 1, x, y + 1);
		grid[y + 1][x] = '.';
	}
	if (y - 1 >= 0 && grid[y - 1][x] != 'X') {
		dfs(curt + 1, x, y - 1);
		grid[y - 1][x] = '.';
	}
}

int main() {
	while (scanf("%d%d%d", &m, &n, &t), m && n && t) {
		flag = false;
		for (int i = 0; i < m; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'S') stx = j, sty = i;
				if (grid[i][j] == 'D') edx = j, edy = i;
			}
		}
		dfs(0, stx, sty);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}