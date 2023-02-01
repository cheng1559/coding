#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t1, t2, tx;
	unordered_map<string, string> mp;
	if (cin >> s, s == "START") {
		while (cin >> t1, t1 != "END") {
			cin >> t2;
			mp[t2] = t1;
		}
	}
	if (cin >> s, s == "START") {
		cin.get();
		while (getline(cin, tx), tx != "END") {
			string tmp, ans;
			for (auto i : tx) {
				if (isalpha(i)) tmp += i;
				else {
					if (tmp.size()) {
						if (mp.count(tmp)) tmp =  mp[tmp];
						ans += tmp;
						tmp.clear();
					}
					ans.push_back(i);
				}
			}
			cout << ans << endl;
		}
	}
}