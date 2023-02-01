#include <bits/stdc++.h>
using namespace std;

int m, n[104], k, ans;

int main() {
	while (cin >> m, m) {
		k = 0, ans = 0;
		for (int i = 0; i < m; i ++) cin >> n[i], k ^= n[i];
		for (int i = 0; i < m; i ++) {
			ans += n[i] > (n[i] ^ k);
		}
		cout << ans << endl;
	}
}