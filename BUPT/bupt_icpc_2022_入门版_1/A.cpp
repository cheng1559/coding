#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int main() {
    int m, n;
    while (cin >> m >> n) {
	    cout << m / gcd(m, n) * n << endl;
    }
}