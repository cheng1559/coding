#include <bits/stdc++.h>

using namespace std;

const int M = 205;
string s;
int cnt[30], ans, a, b;

void bfs() {
	ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i <= 26; i ++) if (cnt[i]) q.push(cnt[i]);
	if (q.size() == 1) ans = q.top();
	while (q.size() > 1) {
		a = q.top(), q.pop();
		b = q.top(), q.pop();
		ans += a + b;
		q.push(a + b);
	}
}

int main() {
	while (cin >> s, s != "END") {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < s.length(); i ++) cnt[s[i] == '_' ? 26 : s[i] - 'A'] ++;
		bfs();
		printf("%d %d %.1f\n", s.length() * 8, ans, s.length() * 8.0 / ans);
	}
}