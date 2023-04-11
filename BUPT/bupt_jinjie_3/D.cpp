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
	
	Point& operator+= (const Point &a) {
		this->x += a.x;
		this->y += a.y;
		return *this;
	}
	
	Point(double _x, double _y): x(_x), y(_y) {}
	Point(): x(0), y(0) {}
};

class V {
public:
	Point a, b;
	double x, y;
	
	friend double operator* (V &va, V &vb) {
		return va.x * vb.y - va.y * vb.x;
	}
	
	friend V operator+ (V &va, V &vb) {
		V ans;
		ans.x = va.x + vb.x;
		ans.y = va.y + vb.y;
		ans.a = va.a + vb.a;
		ans.b = va.b + vb.b;
		return ans;
	}
	
	friend double operator^ (V &va, V &vb) {
		return va.x * vb.x + va.y * vb.y;
	}
	
	friend bool operator< (V &va, V &vb) {
		return va * vb < 0;
	}
	
	friend bool operator> (V &va, V &vb) {
		return va * vb > 0;
	}
	
	V (Point _a, Point _b): a(_a), b(_b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
	
	V(): x(0), y(0) {}
};

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int n;
	while (std::cin >> n, n) {
		std::vector<Point> P(n + 1);
		for (int i = 0; i < n; i ++) {
			double x, y;
			std::cin >> x >> y;
			P[i] = Point(x, y);
		}
		P[n] = P[0];
		
		int flag = 0;
		for (int i = 0; i <= n; i ++) {
			V va(P[i], P[i + 1]), vb(P[i], P[i + 2]);
			if (va < vb) {
				flag = 1;
				break;
			}
		}
		std::cout << (flag ? "concave" : "convex") << "\n";
	}
}