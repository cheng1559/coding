#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct pos{int x, y, z;};

const int M = 55;
int a, b, c, T, t;
int mm[M][M][M];
pos dir[] = {
	{1, 0, 0},
	{0 ,1, 0},
	{0, 0, 1},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1}
};

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d %d %d", &a, &b, &c, &t);
		for (int i = 0; i < a; i ++) 
			for (int j = 0; j < b; j ++)
				for (int k = 0; k < c; k ++) 
					scanf("%d", &mm[i][j][k]);
		queue<pos> q;
		int flag = 1, ans = 0;
		pos s = {0, 0, 0};
		q.push(s);
		while (q.size() && flag) {
			pos cur = q.front();
			q.pop();
			for (int i = 0; i < 6; i ++) {
				int tx = cur.x + dir[i].x, ty = cur.y + dir[i].y, tz = cur.z + dir[i].z;
				if (tx < 0 || tx >= a || ty < 0 || ty >= b || tz < 0 || tz >= c || mm[tx][ty][tz] == 1) continue;
				mm[tx][ty][tz] = 1;
				pos r = {tx, ty, tz};
				q.push(r);
				if (tx == a - 1 && ty == b - 1 && tz == c - 1) flag = 0;
			}
			ans ++;
		}
		if (a == 1 && b == 1 && c == 1) ans = 0;
		if (!flag && ans <= t) printf("%d\n", ans);
		else printf("-1\n");
	}
}