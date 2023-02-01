#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int main() {
    int n, m;
    cin >> n;
    while (n --) {
    	int k = 1, ans = 1;
	    cin >> m;
	    while (m --) {
	    	int r;
	    	cin >> r;
	    	ans = ans / gcd(ans, r) * r;
	    }
	    cout << ans << endl;
    }
}