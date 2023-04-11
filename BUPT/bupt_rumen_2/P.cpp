#include <bits/stdc++.h>
using namespace std;

int vis[15][15];
int fx, fy, tx, ty, ans;
struct p {int x, y, t;};
int mx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int my[] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
	while (~scanf("%c%d %c%d ", &fx, &fy, &tx, &ty)) {
		fx -= 'a', tx -= 'a', fy --, ty --;
		ans = 1e9;
		memset(vis, 0, sizeof vis);
		queue<p> q;
		q.push({fx, fy, 0});
		memset(vis, 0, sizeof vis);
		while (q.size()) {
			p tmp = q.front();
			q.pop();
			if (tmp.x < 0 || tmp.x >= 8 || tmp.y < 0 || tmp.y >= 8) continue;
			if (vis[tmp.x][tmp.y]) continue;
			vis[tmp.x][tmp.y] = 1;
			if (tmp.x == tx && tmp.y == ty) ans = min(tmp.t, ans);
			for (int i = 0; i < 8; i ++) {
				q.push({tmp.x + mx[i], tmp.y + my[i], tmp.t + 1});
			}
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",fx + 'a', fy + 1, tx + 'a', ty + 1, ans);
	}
}