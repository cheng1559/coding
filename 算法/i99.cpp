#include <bits/stdc++.h>
using namespace std;

class i99 {
public:
	vector<int> num;
	i99() {}
	i99(int n) {
		while (n) {
			num.push_back(n % 10);
			n /= 10;
		}
	}
	i99(string n) {
		for (int i = n.length() - 1; i >= 0; i --) {
			num.push_back(n[i] - '0');
		}
	}
	i99 operator+ (i99 b) {
		i99 a = *this, c;
		if (a.num.size() < b.num.size()) swap(a, b);
		int t = 0;
		for (int i = 0; i < a.num.size(); i++) {
			t += a.num[i];
			if (i < b.num.size()) t += b.num[i];
			c.num.push_back(t % 10);
			t /= 10;
		}
		if (t) c.num.push_back(1);
		return c;
	}
	i99 operator-(i99 b) {
		i99 a = *this, c;
		int t = 0;
		for (int i = 0; i < a.num.size(); i++) {
			t = a.num[i] - t;
			if (i < b.num.size()) t -= b.num[i];
			c.num.push_back((t + 10) % 10);
			t = t < 0 ? 1 : 0;
		}
		while (c.num.size() > 1 && c.num.back() == 0) c.num.pop_back();
		return c;
	}
	
	i99 operator* (int b) {
		i99 a = *this;
		if (b == 0) return i99(0);
		i99 c;
		int t = 0;
		for (int i = 0; i < a.num.size() || t; i++) {
			if (i < a.num.size()) t += a.num[i] * b;
			c.num.push_back(t % 10);
			t /= 10;
		}
		return c;
	}
	
	string print() {
		string t;
		for (int i = num.size() - 1; i >= 0; i --) t += num[i] + '0';
		return t;
	}
};

int main() {
	i99 ans(1), a(2);
	int n = 1e8;
	
	while (n) {
		if (n % 2) ans = ans * a;
		n >>= 1;
		a = a * a;
	}
	cout << a.print();
}

