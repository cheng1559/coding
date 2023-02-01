#include <bits/stdc++.h>
using namespace std;

int k, m, sg;

int main() {
	while (cin >> m, m) {
		sg = 0;
		for (int i = 0; i < m; i ++) cin >> k, sg ^= k;
		cout << (sg ? "Rabbit Win!" : "Grass Win!") << endl;
	}
}