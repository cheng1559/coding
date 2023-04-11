#include <bits/stdc++.h>


class Point {
public:
	double x, y;
	friend Point operator+ (Point &a, Point &b) {
		Point ans;
		ans.x = a.x + b.x;
		ans.y = a.y + b.y;
		return ans;
	}
	
	friend double dis(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a. y - b.y));
	}
	
	friend bool operator== (Point a, Point b) {
		return a.x == b.x && a.y == b.y;
	}
	
	friend bool operator!= (Point a, Point b) {
		return a.x != b.x || a.y != b.y;
	}
	
	friend bool operator< (Point a, Point b) {
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	}
	
	friend bool operator> (Point a, Point b) {
		return a.y == b.y ? a.x > b.x : a.y > b.y;
	}
	
	Point(double _x, double _y): x(_x), y(_y) {}
	Point(): x(0), y(0) {}
};

class V {
public:
	Point a, b;
	double x, y;
	
	friend double operator* (V va, V vb) {
		return va.x * vb.y - va.y * vb.x;
	}
	
	friend V operator+ (V va, V vb) {
		V ans;
		ans.x = va.x + vb.x;
		ans.y = va.y + vb.y;
		ans.a = va.a + vb.a;
		ans.b = va.b + vb.b;
		return ans;
	}
	
	friend double operator^ (V va, V vb) {
		return va.x * vb.x + va.y * vb.y;
	}
	
	friend double dis(V va) {
		return sqrt(va.x * va.x + va.y * va.y);
	}
	
	V (Point _a, Point _b): a(_a), b(_b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
	
	V(): x(0), y(0) {}
};

std::vector<Point> convex_hull(std::vector<Point> &P) {
	int n = P.size();
	Point s = *std::min_element(P.begin(), P.end());
	auto cmp = [&](Point &a, Point &b) {
		V va(s, a), vb(s, b);
		double m = va * vb;
		return m == 0 ? dis(va) < dis(vb) : m > 0;
	};
	std::sort(P.begin(), P.end(), cmp);
	std::vector<Point> st {P[0], P[1]};
	for (int i = 2; i < n; i ++) {
		while (V(st[st.size() - 1], P[i]) * V(st[st.size() - 1], st[st.size() - 2]) <= 0) {
			st.pop_back();
		}
		st.push_back(P[i]);
	}
	return st;
}

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;



int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(2);
	
	int n;
	while (std::cin >> n, n) {
		std::vector<Point> P(n);
		for (int i = 0; i < n; i ++) {
			std::cin >> P[i].x >> P[i].y;
		}
		double ans = 0;
		if (P.size() == 2) {
			std::cout << dis(P[0], P[1]) << "\n";
			continue;
		}
		auto t = convex_hull(P);
		for (int i = 0; i < t.size(); i ++) {
			ans += dis(t[i], t[(i + 1) % t.size()]);
		}
		std::cout << ans << "\n";
	}
}