#include <bits/stdc++.h>
using namespace std;
struct node {int l[3]; int t;};

const int M = 105;
bool vis[M][M][M], flag;
int op[][2] = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 2}, {2, 1}};
int L[3], ans;

int bfs() {
	int ans = 0;
	flag = false;
	memset(vis, 0, sizeof vis);
	if (L[0] & 1) return -1;
	queue<node> q;
	node start = {{L[0], 0, 0}, 0};
	q.push(start);
	while (q.size()) {
		node cur = q.front();
		q.pop();
		if (vis[cur.l[0]][cur.l[1]][cur.l[2]]) continue;
		vis[cur.l[0]][cur.l[1]][cur.l[2]] = true;
		if (!cur.l[0] && cur.l[1] == cur.l[2] || !cur.l[1] && cur.l[0] == cur.l[2] || !cur.l[2] && cur.l[0] == cur.l[1])
			return cur.t;
		for (int i = 0; i < 6; i ++) {
			node next = cur;
			int from = op[i][0], to = op[i][1];
			if (cur.l[from] + cur.l[to] > L[to]) {
				next.l[to] = L[to];
				next.l[from] -= L[to] - cur.l[to];
			}
			else {
				next.l[to] += cur.l[from];
				next.l[from] -= cur.l[from];
			}
			next.t ++;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	cin.tie(0), cout.tie(0);
	while (cin >> L[0] >> L[1] >> L[2], L[0] || L[1] || L[2]) {
		ans = bfs();
		if (~ans) cout << ans << "\n";
		else cout << "NO\n";
	}
}

