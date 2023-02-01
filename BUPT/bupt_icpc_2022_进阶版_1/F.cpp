#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	while (cin >> s, s[0] != '-') {
		int ans = 0, cnt1 = 0, cnt2 = 0;
		stack<int> st;
		for (auto i : s) {
			if (st.size() && st.top() == '{' && i == '}') st.pop();
			else st.push(i);
		}
		while (st.size()) {
			cnt1 += st.top() == '{', cnt2 += st.top() == '}';
			st.pop();
		}
		ans = (cnt1 + cnt2 >> 1) + cnt1 % 2;
		cout << ++cnt << ". " << ans << endl;
	}
}