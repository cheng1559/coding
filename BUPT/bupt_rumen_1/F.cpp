#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld f(ld x) {
	return pow(x, 4) * 8 + pow(x, 3) * 7 + pow(x, 2) * 2 + x * 3 + 6;
}

int main() {
	int T;
	cin >> T;
	while (T --) {
		ld l = 0, r = 100, y;
		cin >> y;
		while (r - l > 1e-15) {
			ld mid = (l + r) / 2;
			if (f(mid) > y) r = mid;
			else l = mid;
		}
		if (fabs(f(l) - y) < 1e-6) cout << fixed << setprecision(4) << l << endl;
		else cout << "No solution!" << endl;
	}
}