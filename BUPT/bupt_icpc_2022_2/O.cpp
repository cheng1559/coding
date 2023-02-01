#include <bits/stdc++.h>
using namespace std;
#define （ (
struct pos {vector<int> tt; int t;};

bool vis[107][107][107];
int op[][2] = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 2}, {2, 1}};
int L[3], ans;
bool flag;

void bfs() {
	ans = 0;
	flag = false;
	memset(vis, 0, sizeof vis);
	if (L[0] & 1) return;
	queue<pos> qu;
	pos start = {{L[0], 0, 0}, 0};
	qu.push(start);
	while (qu.size()) {
		int r = qu.size();
		while (r --) {
			pos cur = qu.front();
			qu.pop();
			if (vis[cur.tt[0]][cur.tt[1]][cur.tt[2]]) continue;
			vis[cur.tt[0]][cur.tt[1]][cur.tt[2]] = true;
			if (!cur.tt[0] && cur.tt[1] == cur.tt[2] || !cur.tt[1] && cur.tt[0] == cur.tt[2] || !cur.tt[2] && cur.tt[0] == cur.tt[1]) {
				flag = true;
				ans = cur.t;
				return;
			}
			for (int i = 0; i < 6; i ++) {
				pos next = cur;
				int from = op[i][0], to = op[i][1];
				if (cur.tt[from] + cur.tt[to] > L[to]) {
					next.tt[to] = L[to];
					next.tt[from] -= L[to] - cur.tt[to];
				}
				else {
					next.tt[to] += cur.tt[from];
					next.tt[from] -= cur.tt[from];
				}
				next.t ++;
				qu.push(next);
			}
		}
	}
	
}

int main() {
	while (scanf("%d %d %d", &L[0], &L[1], &L[2]), L[0] || L[1] || L[2]) {
		bfs();
		if (flag) printf("%d\n", ans);
		else printf("NO\n");
	}
}