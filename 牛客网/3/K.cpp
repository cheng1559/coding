#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

ll b[200004], c[2000004];

const ll Mod = 1e9 + 7;

inline ll qpow(ll a, ll n, ll M = Mod) {
	ll ans = 1;
	while (n > 0) {
		a %= M;
		if (n & 1) ans = ans * a % M;
		n >>= 1, a = a * a;
	}
	return ans;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	
	int n, t;
	map<int, int> mp;
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> t, mp[t] ++;
	int n2 = 0;
	for (auto i : mp) c[++ n2] = i.first;
	vi d = {0};
	int k = n;
	for (int i = 1; i <= n2; i ++) {
		for (int j = 0; j < c[i] - c[i - 1]; j ++) d.push_back(k);
		k -= mp[c[i]];
	}
	
	n = d.size() - 1;
	b[0] = 1;
	for (int i = 1; i <= n; i ++) {
		b[i] = b[i - 1] * qpow(i, d[i - 1] - d[i]) % Mod;
		ll k = (i + 1) * b[i] % Mod * (qpow(i + 1, d[i]) - qpow(i, d[i]) + Mod) % Mod;
		ans += k;
		ans %= Mod;
    }
	cout << ans << "\n";
}