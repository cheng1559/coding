#include <bits/stdc++.h>
using namespace std;

struct n {string name; int num; int time;} s[10006];

bool cmp(n a, n b) {
	if (a.num == b.num) return a.time < b.time;
	return a.num > b.num;
}

int main() {
	int c;
	cin >> c;
	while (c --) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string name;
			int num, time;
			cin >> name >> num >> time;
			s[i].name = name;
			s[i].num = num;
			s[i].time = time;
		}
		sort(s, s + n, cmp);
		for (int i = 0; i < m; i++) {
			cout << s[i].name << " " << s[i].num << " " << s[i].time << endl;
		}
	}
}