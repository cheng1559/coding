#include <bits/stdc++.h>
using namespace std;

int C, m, n, sg;

int main() {
	cin >> C;
	while (C --) {
		cin >> n >> m;
		cout << (n % (m + 1) ? "Grass" : "Rabbit") << endl;
	}
}