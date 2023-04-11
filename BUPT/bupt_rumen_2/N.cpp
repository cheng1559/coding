#include <bits/stdc++.h>
using namespace std;

struct node {int floor, t;};
int k[205], vis[205], n, a, b;

int bfs() {
	queue<node> q;
	memset(vis, 0, sizeof vis);
	node s = {a, 0};
	q.push(s);
	while (q.size()) {
		int r = q.size();
		while (r --) {
			node cur = q.front();
			q.pop();
			if (vis[cur.floor]) continue;
			vis[cur.floor] = 1;
			if (cur.floor == b) {
				return cur.t;
			}
			if (cur.floor + k[cur.floor] <= n) {
				node next = {cur.floor + k[cur.floor], cur.t + 1};
				q.push(next);
			}
			if (cur.floor - k[cur.floor] >= 1) {
				node next = {cur.floor - k[cur.floor], cur.t + 1};
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	while (scanf("%d", &n), n) {
		scanf("%d %d", &a, &b);
		for (int i = 1; i <= n; i ++) scanf("%d", k + i);
		printf("%d\n", bfs());
	}
}