#include <bits/stdc++.h>
using namespace std;

int s[10006];

int main() {
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int k = 0; k < n; k++) {
			sort(s + k, s + n, [](int a, int b) {return a > b;});
			for (int i = 0; i < s[k]; i++) s[k + i + 1] --;
			s[k] = min(s[k], 0);
		}
		bool flag = true;
		for (int i = 0; i < n; i++) if (s[i] != 0) flag = false;
		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}