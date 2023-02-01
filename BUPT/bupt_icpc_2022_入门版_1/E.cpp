#include <bits/stdc++.h>
using namespace std;

int fib[10] = {1, 2, 0, 2, 2, 1, 0, 1};

int main() {
	int n;
	while (cin >> n) {
		if (fib[n % 8] == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}