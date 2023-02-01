#include <bits/stdc++.h>
using namespace std;
#define sq2(a) ((a) * (a))
#define INF 1e5


double dis(double x1, double y1, double x2, double y2) {
	return sqrt(sq2(x1 - x2) + sq2(y1 - y2));
}

const double pi = acos(-1);

double cos(double x1, double y1, double x2, double y2, double x3, double y3) {
	
	double dx1 = x1 - x2, dy1 = y1 - y2;
	double dx2 = x3 - x2, dy2 = y3 - y2;
	double ans = (dx1 * dx2 + dy1 * dy2) / (dis(0, 0, dx1, dy1) * dis(0, 0, dx2, dy2));
	return ans;
	
	double k1, k2;
	double de1, de2;
	if (x1 == x2) de1 = y1 > y2 ? pi / 4 : pi / 4 * 3;
	else k1 = (y2 - y1) / (x2 - x1), de1 = atan(k1);
	if (x2 == x3) de2 = y1 > y2 ? pi / 4 : pi / 4 * 3;
	else k2 = (y3 - y2) / (x3 - x2), de2 = atan(k2);
	
	cout << de1 << " " << de2 << endl;
	
	return de1 - de2;
}



bool eq(double a, double b) {
	return fabs(a - b) < 1e-5;
}


int main() {
	int T;
	cin >> T;
	while (T --) {
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		
		double d1 = dis(x1, y1, x2, y2);
		double d2 = dis(x2, y2, x3, y3);
		
		
		double c1 = cos(x1, y1, x2, y2, x3, y3);
		
		
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		double d3 = dis(x1, y1, x2, y2);
		double d4 = dis(x2, y2, x3, y3);
		
		//cout << d1 << " " << d2 << endl;
		//cout << d3 << " " << d4 << endl;
		
		if (!eq(d1, d3)) swap(x1, x3), swap(y1, y3);
		
		
		double c2 = cos(x1, y1, x2, y2, x3, y3);
		//cout << c1 << endl;
		//cout << c2 << endl;
		
		cout << (eq(d1, d2) || eq(c1, c2) ? "NO" : "YES") << endl;
	}
}