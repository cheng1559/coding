#include <bits/stdc++.h>
using namespace std;

int a[10005], b[10005];

int main() {
	int n;
    while (scanf("%d", &n), n) {
        int ans = 0;
        if (!n) break;
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", b + i);
        sort(a, a + n), sort(b, b + n);
        int i = 0, j = 0;
        while (i < n && j < n) {
        	while (i < n && a[i] < b[j]) i++;
        	if (i < n) ans += 200, i++, j++;
        }
        ans -= (n - ans / 200) * 200;
        printf("%d\n", ans);
    }
}