#include <bits/stdc++.h>
using namespace std;

const int M = 1004;
int m, n, p, fib[25] = {0, 1, 2}, sg[M];
bool vis[M];

void SG() {
	for (int i = 0; i <= 1000; i ++) {
		memset(vis, 0, sizeof vis);
		for (int j = 1; fib[j] <= i; j ++) vis[sg[i - fib[j]]] = true;
		for (int j = 0; j <= 1000; j ++) {
			if (!vis[j]) {
				sg[i] = j;
				break;
			}
		}
	}
}

int main() {
	for (int i = 3; i <= 20; i ++) fib[i] = fib[i - 1] + fib[i - 2];
	SG();
	while (cin >> m >> n >> p, m || n || p) {
		int flag = sg[m] ^ sg[n] ^ sg[p];
		cout << (flag ? "Fibo" : "Nacci") << endl;
	}
}