#include <iostream>

using namespace std;
using ll = long long;

const ll M = 1e9 + 7;

inline ll f_pow(ll a, ll n) {
	ll ans = 1;
	while (n) {
		a %= M;
		if (n & 1) ans = ans * a % M;
		n >>= 1, a = a * a;
	}
	return ans;
}