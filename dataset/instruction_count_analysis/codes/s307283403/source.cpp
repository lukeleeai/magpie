#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

using namespace std;

long long p[200000], q[200000], n, k;

int main() {

	cin >> n >> k;

	for (long long i = 1; i <= n; i++) {

		long long a; cin >> a;

		if (a > 0)p[i] += a;

		q[i] += a;

	}

	for (long long i = 1; i < 200000; i++)p[i] += p[i - 1];

	for (long long i = 1; i < 200000; i++)q[i] += q[i - 1];

	long long maxn = 0;

	for (long long i = 1; i <= n; i++) {

		long long L = i, R = i + k - 1;//区間[L, R]は制限される

		long long L1 = 1, R1 = L - 1;//区間[1, L-1]は制限されない

		long long L2 = R + 1, R2 = n;//区間[R+1, n]は制限されない

		if (R > n)continue;

		long long w1 = q[R] - q[L - 1];

		long long w2 = p[R1] - p[L1 - 1];

		long long w3 = p[R2] - p[L2 - 1];

		maxn = max(maxn, w1 + w2 + w3);

	}

	for (long long i = 1; i <= n; i++) {

		long long L = i, R = i + k - 1;//区間[L, R]は制限される

		long long L1 = 1, R1 = L - 1;//区間[1, L-1]は制限されない

		long long L2 = R + 1, R2 = n;//区間[R+1, n]は制限されない

		if (R > n)continue;

		long long w1 = 0;

		long long w2 = p[R1] - p[L1 - 1];

		long long w3 = p[R2] - p[L2 - 1];

		maxn = max(maxn, w1 + w2 + w3);

	}

	cout << maxn << endl;

	return 0;

}