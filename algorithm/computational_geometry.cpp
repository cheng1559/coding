#include <bits/stdc++.h>

class Point {
public:
	double x, y;
	friend Point operator+ (Point a, Point b) {
		Point ans;
		ans.x = a.x + b.x;
		ans.y = a.y + b.y;
		return ans;
	}
	
	friend Point operator- (Point a, Point b) {
		Point ans;
		ans.x = a.x - b.x;
		ans.y = a.y - b.y;
		return ans;
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
	
	friend double operator* (V va, V vb) { // cross
		return va.x * vb.y - va.y * vb.x;
	}
	
	friend double operator^ (V va, V vb) { // dot
		return va.x * vb.x + va.y * vb.y;
	}
	
	friend V operator+ (V va, V vb) {
		V ans;
		ans.x = va.x + vb.x;
		ans.y = va.y + vb.y;
		ans.a = va.a + vb.a;
		ans.b = va.b + vb.b;
		return ans;
	}
	
	friend V operator- (V va, V vb) {
		V ans;
		ans.x = va.x - vb.x;
		ans.y = va.y - vb.y;
		ans.a = va.a - vb.a;
		ans.b = va.b - vb.b;
		return ans;
	}
	
	friend bool operator== (V va, V vb) {
		return va.x == vb.x && va.y == vb.y;
	}
	
	friend bool operator!= (V va, V vb) {
		return va.x != vb.x || va.y != vb.y;
	}
	
	V (Point _a, Point _b): a(_a), b(_b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
	
	V(): x(0), y(0) {}
};

double cross(Point a, Point b, Point c) {
	V va(b, a), vb(b, c);
	return va * vb;
}

double area(Point a, Point b, Point c) {
	return fabs(cross(a, b, c) / 2);
}

double dis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a. y - b.y));
}

double dis(V va) {
	return sqrt(va.x * va.x + va.y * va.y);
}

std::vector<Point> convex_hull(std::vector<Point> &P) {
	int n = P.size();
    if (n <= 2) return P;
	Point s = *std::min_element(P.begin(), P.end());
	auto cmp = [&](Point &a, Point &b) {
		V va(s, a), vb(s, b);
		double m = va * vb;
		return m == 0 ? dis(va) < dis(vb) : m > 0;
	};
	std::sort(P.begin(), P.end(), cmp);
    int r = n - 1;
    while (r >= 0 && cross(P[0], P[n - 1], P[r]) == 0) r --;
    for (int l = r + 1, h = n - 1; l < h; l++, h--) std::swap(P[l], P[h]);
	std::vector<Point> st;
	st.push_back(P[0]);
	st.push_back(P[1]);
	for (int i = 2; i < n; i ++) {
		while (cross(P[i], st[st.size() - 1], st[st.size() - 2]) < 0) {
			st.pop_back();
		}
		st.push_back(P[i]);
	}
	return st;
}


