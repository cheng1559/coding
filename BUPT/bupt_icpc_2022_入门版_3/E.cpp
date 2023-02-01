#include <bits/stdc++.h>
using namespace std;

int C, n, m;

int main() {
	cin >> C;
	while (C --) {
		cin >> n >> m;
		cout << (n % (m + 1) ? "first" : "second") << endl;
	}
}