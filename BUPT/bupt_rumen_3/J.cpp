#include <bits/stdc++.h>
using namespace std;

int m, n;

int main() {
	while (cin >> m) {
		cin >> n;
		if (m % (n + 1)) {
			for (int i = 1; i <= n; i ++) {
				if ((m - i) % (n + 1) == 0 || m < i) cout << i << " ";
			}
			cout << endl;
		}
		else cout << "none" << endl;
	}
}