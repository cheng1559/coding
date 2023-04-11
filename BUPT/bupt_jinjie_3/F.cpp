#include <bits/stdc++.h>

using ll = __int64_t;
#define double ll
class Point {
public:
	double x, y;
	friend Point operator+ (Point &a, Point &b) {
		Point ans;
		ans.x = a.x + b.x;
		ans.y = a.y + b.y;
		return ans;
	}
	friend bool operator== (Point &a, Point &b) {
		return a.x == b.x && a.y == b.y;
	}
	
	Point& operator+= (const Point &a) {
		this->x += a.x;
		this->y += a.y;
		return *this;
	}
	friend double dis(Point a, Point b) {
		return abs(a.x - b.x) + abs(a.y - b.y);
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
	
	friend bool intersect(V &va, V &vb) {
		V p1(va.a, vb.a), p2(va.a, vb.b);
		V p3(vb.a, va.a), p4(vb.a, va.b);
		double d1 = (p1 * va);
		double d2 = (p2 * va);
		double d3 = (p3 * vb);
		double d4 = (p4 * vb);
		
		if (d1 * d2 * d3 * d4 == 0) {
			if (d1 == 0) {
				return vb.a.x <= std::max(va.a.x, va.b.x) && 
					   vb.a.x >= std::min(va.a.x, va.b.x) &&
					   vb.a.y <= std::max(va.a.y, va.b.y) && 
					   vb.a.y >= std::min(va.a.y, va.b.y);
			}
			if (d2 == 0) {
				return vb.b.x <= std::max(va.a.x, va.b.x) && 
					   vb.b.x >= std::min(va.a.x, va.b.x) &&
					   vb.b.y <= std::max(va.a.y, va.b.y) && 
					   vb.b.y >= std::min(va.a.y, va.b.y);
			}
			if (d3 == 0) {
				return va.a.x <= std::max(vb.a.x, vb.b.x) && 
					   va.a.x >= std::min(vb.a.x, vb.b.x) &&
					   va.a.y <= std::max(vb.a.y, vb.b.y) && 
					   va.a.y >= std::min(vb.a.y, vb.b.y);
			}
			if (d4 == 0) {
				return va.b.x <= std::max(vb.a.x, vb.b.x) && 
					   va.b.x >= std::min(vb.a.x, vb.b.x) &&
					   va.b.y <= std::max(vb.a.y, vb.b.y) && 
					   va.b.y >= std::min(vb.a.y, vb.b.y);
			}
		}
		return d1 * d2 < 0 && d3 * d4 < 0;
	}
	
	V(): x(0), y(0) {}
};

using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;

void solve() {
	Point a, b, c, d;
	std::cin >> a.x >> a.y >> b.x >> b.y;
	std::cin >> c.x >> c.y >> d.x >> d.y;
	V va(a, b), vb(c, d);
	int t1 = c.x <= std::max(a.x, b.x) && c.x >= std::min(a.x, b.x);
	int t2 = c.y <= std::max(a.y, b.y) && c.y >= std::min(a.y, b.y);
	int t3 = d.x <= std::max(a.x, b.x) && d.x >= std::min(a.x, b.x);
	int t4 = d.y <= std::max(a.y, b.y) && d.y >= std::min(a.y, b.y);
	
	int t5 = a.x <= std::max(c.x, d.x) && a.x >= std::min(c.x, d.x);
	int t6 = a.y <= std::max(c.y, d.y) && a.y >= std::min(c.y, d.y);
	int t7 = b.x <= std::max(c.x, d.x) && b.x >= std::min(c.x, d.x);
	int t8 = b.y <= std::max(c.y, d.y) && b.y >= std::min(c.y, d.y);
	
	
	if (va * vb == 0 && (b.y - a.y) * (c.x - a.x) == (c.y - a.y) * (b.x - a.x) && (((t1 && t2) || (t3 && t4)) || ((t5 && t6) || (t7 && t8)))) {
		if (a == b) {
			std::cout << 1 << "\n";
			std::cout << a.x << " " << a.y << "\n";
		}
		else if (c == d) {
			std::cout << 1 << "\n";
			std::cout << c.x << " " << c.y << "\n";
		}
		else if (a == c && dis(b, d) == dis(a, b) + dis(c, d)) {
			std::cout << 1 << "\n";
			std::cout << a.x << " " << a.y << "\n";
		}
		else if (a == d && dis(b, c) == dis(a, c) + dis(c, d)) {
			std::cout << 1 << "\n";
			std::cout << a.x << " " << a.y << "\n";
		}
		else if (b == c && dis(a, d) == dis(a, b) + dis(c, d)) {
			std::cout << 1 << "\n";
			std::cout << b.x << " " << b.y << "\n";
		}
		else if (b == d && dis(a, c) == dis(a, b) + dis(c, d)) {
			std::cout << 1 << "\n";
			std::cout << b.x << " " << b.y << "\n";
		}
		else std::cout << "INF" << "\n";
		return;
	}
	if (intersect(va, vb)) {
		std::cout << 1 << "\n";
		ll x1 = (d.x * c.y - d.y * c.x) * (b.x - a.x) - (b.x * a.y - b.y * a.x) * (d.x - c.x);
		ll x2 = (b.y - a.y) * (d.x - c.x) - (d.y - c.y) * (b.x - a.x);
		int nagx = x1 * x2 < 0;
		x1 = abs(x1), x2 = abs(x2);
		if (x1 == 0) {
			std::cout << x1;
		}
		else {
			ll g1 = std::__gcd(x1, x2);
			x1 = x1 / g1;
			x2 = x2 / g1;
			if (nagx) std::cout << "-";
			std::cout << x1;
			if (x2 != 1) std::cout << "/" << x2;
		}
		std::cout << " ";
		
		ll y1 = (b.y - a.y) * (d.x * c.y - c.x * d.y) - (d.y - c.y) * (b.x * a.y - a.x * b.y);
		ll y2 = (b.y - a.y) * (d.x - c.x) - (d.y - c.y) * (b.x - a.x);
		int nagy = y1 * y2 < 0;
		y1 = abs(y1), y2 = abs(y2);
		
		if (y1 == 0) {
			std::cout << y1;
		}
		else {
			ll g2 = std::__gcd(y1, y2);
			y1 = y1 / g2;
			y2 = y2 / g2;
			if (nagy) std::cout << "-";
			std::cout << y1;
			if (y2 != 1) std::cout << "/" << y2;
		}
		std::cout << "\n";
	}
	else {
		std::cout << 0 << "\n";
	}
}

int main() {
	std::cin.tie(0), std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
}