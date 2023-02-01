#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

int n;
string o1, o2, tmp1, tmp2;
vector<string> op, ans;

void dfs(int n) {
	if (!n) {
		if (tmp2 == o2) ans = op;
		return;
	}
	if (!o1.empty()) {
		int r = o1.back();
		tmp1 += r;
		o1.pop_back();
		op.push_back("in");
		dfs(n - 1);
		o1.push_back(r);
		tmp1.pop_back();
		op.pop_back();
	}
	if (!tmp1.empty()) {
		int r = tmp1.back();
		tmp2 += r;
		tmp1.pop_back();
		op.push_back("out");
		dfs(n - 1);
		tmp1.push_back(r);
		tmp2.pop_back();
		op.pop_back();
	}
}

int main() {
	while (cin >> n >> o1 >> o2) {
		ans.clear();
		reverse(o1.begin(), o1.end());
		dfs(n << 1);
		if (ans.size()) {
			cout << "Yes." << endl;
			for (auto i : ans) cout << i << endl;
		}
		else {
			cout << "No." << endl;
		}
		cout << "FINISH" << endl;
	}
	
}