#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;

const int M = 1e9 + 7;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	vi a(n);
	for (int i = 0; i < n / 2; i ++) {
		a[n - i - 1] = (i + 1) * 2;
		a[i] = i * 2 + 1;
	}
	a[n / 2] = n;
	
	
	ll ans = 0;
	vvll t(n, vll(n));
	t[0][0] = 1;
	for (int i = 1; i < n; i ++) {
		t[i][0] = 1;
		for (int j = 1; j <= i; j ++) {
			t[i][j] = (t[i - 1][j] + t[i - 1][j - 1]) % M;
		}
	}
	for (int i = 0; i < n; i ++) ans = (ans + t[n - 1][i] * a[i] % M) % M;
	std::cout << ans << "\n";
	
	for (int i = 0; i < n; i ++) std::cout << a[i] << " ";
	std::cout << "\n";
}