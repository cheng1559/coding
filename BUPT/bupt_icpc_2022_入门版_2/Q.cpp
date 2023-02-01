#include <bits/stdc++.h>

using namespace std;

const int M = 205;
char g[M][M];
int m, n, sx, sy, ans;
int x[] = {1, 0, -1, 0}, y[] = {0, 1, 0, -1};

struct node {
	int x, y, t;
	bool operator< (const node &b) const {return this->t > b.t;}
};

void bfs() {
	ans = -1;
	priority_queue<node> q;
	node s = {sx, sy, 0};
	q.push(s);
	while (q.size()) {
		node cur = q.top();
		q.pop();
		if (g[cur.y][cur.x] == 'r') {ans = cur.t; return;}
		g[cur.y][cur.x] = '#';
		for (int i = 0; i < 4; i ++) {
			int tx = cur.x + x[i], ty = cur.y + y[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			if (g[ty][tx] == '.' || g[ty][tx] == 'r') q.push({tx, ty, cur.t + 1});
			if (g[ty][tx] == 'x') q.push({tx, ty, cur.t + 2});
		}
	}
}

int main() {
	while (~scanf("%d %d", &m, &n)) {
		for (int i = 0; i < m; i ++) {
			scanf("%s", g[i]);
			for (int j = 0; j < n; j ++) 
				if (g[i][j] == 'a') sx = j, sy = i;
		}
		bfs();
		if (~ans) printf("%d\n", ans);
		else printf("Poor ANGEL has to stay in the prison all his life.\n");
		
	}
}