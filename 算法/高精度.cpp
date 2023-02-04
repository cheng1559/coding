#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--) if (A[i] != B[i]) return A[i] > B[i];
	return true;
}

vector<int> add(vector<int> &A, vector<int> &B) {
	if (A.size() < B.size()) return add(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(1);
	return C;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		t = t < 0 ? 1 : 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

vector<int> mul(vector<int> &A, int B) {
	if (B == 0) return {0};
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if (i < A.size()) t += A[i] * B;
		C.push_back(t % 10);
		t /= 10;
	}
	//while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

vector<int> div(vector<int> &A, int B, int &r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = A[i] + r * 10;
		C.push_back(r / B);
		r %= B;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}


int main() {
	string a;
	vector<int> A;
	int B, r;
	cin >> a >> B;
	for (int i = a.length() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	auto C = div(A, B, r);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl << r;
}
