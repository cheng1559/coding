#include <bits/stdc++.h>
using namespace std;

int is_prime[100007], prime[100007], k;
int main() {
	const int n = 100000;
	for (int i = 2; i <= n; i++) is_prime[i] = 1;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[k++] = i;
			
		}
		for (int j = 0; prime[j] * i <= n; j ++) {
			is_prime[prime[j] * i] = 0;
			if (i % prime[j] == 0) break;
		}
	}
	int cnt = 0, i = 0;
	while (cnt < 1000) {
		if (is_prime[i]) {
			cnt ++, printf("%5d", i);
			if (cnt % 5 == 0) printf("\n");
		}
		i ++;
	}
}