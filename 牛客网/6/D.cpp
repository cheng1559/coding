#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vvi = std::vector<vi>;
using vvll = std::vector<vll>;
using pii = std::pair<int, int>;
using pllll = std::pair<ll, ll>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	std::string s;
	std::cin >> s;

	
	int n = s.size();
	// s[n - 2] = 'a';
	vvll dp(4, vll(n + 1, 0)), dp2(3, vll(n + 1, 0));
	
	for (int i = 0; i <= n; i ++) dp[0][i] = 1;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = dp[i][j - 1] + (s[j - 1] == "udu"[i - 1] ? dp[i - 1][j - 1] : 0);
		}
	}
	std::string s2 = s;
	std::reverse(s2.begin(), s2.end());
	
	
	for (int i = 0; i <= n; i ++) dp2[0][i] = 1;
	for (int i = 1; i <= 2; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp2[i][j] = dp2[i][j - 1] + (s2[j - 1] == "ud"[i - 1] ? dp2[i - 1][j - 1] : 0);
		}
	}
	int k = 0;
	std::vector<pllll> q;
	vll cnt(n + 1);
	for (int i = 1; i <= n; i ++) cnt[i] = cnt[i - 1] + (s[i - 1] == 'u');
	
	for (int i = 1; i <= n; i ++) {
		ll k = 0;
		if (s[i - 1] == 'd') k = (cnt[i - 1] - cnt[0]) * (cnt[n] - cnt[i]);
		if (s[i - 1] == 'u') k = dp[2][i - 1] + dp2[2][n - i];
		q.push_back({i, k});
	}
	// for (auto i : q) std::cout << i.first << " " << i.second << "\n";
	sort(q.begin(), q.end(), [](pllll a, pllll b) { return a.second > b.second; });
	if (q.size()) s[q[0].first - 1] = 'a';
	//std::cout << q[0].first - 1 << "\n";
	std::cout << s << "\n";
	
}