#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

char map[808][808];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct node {int x, y, t;};

int n, m, xs, ys, q;
int t[808][808];

void bfs() {
	std::queue<node> q;
	q.push({xs, ys, 0});
	memset(t, -1, sizeof t);
	while (q.size()) {
		int r = q.size();
		while (r --) {
			node tmp = q.front();
			q.pop();
			if (map[x][x] == '#' || ~t[x][y]) continue;
			t[tmp.x][tmp.y] = tmp.t;
			
			for (int i = 0; i < 4; i ++) {
				int tx = tmp.x + dx[i], ty = tmp.y + dy[i];
				if (map[tx][ty] == '#' || ~t[tx][ty]) continue;
				q.push({tx, ty, tmp.t + 1});
			}
		}
	}
}

int query(int x, int y) {
	int ct = 0;
	int ans = 1e9;
	while (ct <= 1000) {

		if (map[x][y] == 'U' && map[x - 1][y] != '#') x --;
		else if (map[x][y] == 'R' && map[x][y + 1] != '#') y ++;
		else if (map[x][y] == 'L' && map[x][y - 1] != '#') y --;
		else if (map[x][y] == 'D' && map[x + 1][y] != '#') x ++;
		//std::cout << x << " " << y << "\n";
		ct ++;
		if (~t[x][y] && ct >= t[x][y]) {
			ans = std::min(ans, ct);
		}
		
	}
	if (ans == 1e9) return -1;
	else return ans;
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> n >> m >> xs >> ys >> q;
	for (int i = 0; i < n; i ++) {
		std::cin >> map[i];
	}
	bfs();
	while (q --) {
		int x, y;
		std::cin >> x >> y;
		std::cout << query(x, y) << "\n";
	}
	
}