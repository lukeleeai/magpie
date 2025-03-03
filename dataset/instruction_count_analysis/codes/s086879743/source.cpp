#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#include <functional>

#include <queue>

#include <string>

#include <map>

using namespace std;



long long N, K, A[200009], B[200009], maxn;



int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {

		cin >> A[i]; B[i] = max(A[i], 0LL);

	}

	for (int i = 1; i <= N; i++) A[i] += A[i - 1];

	for (int i = 1; i <= N; i++) B[i] += B[i - 1];



	for (int i = 1; i <= N - K + 1; i++) {

		long long E1 = B[N] - (B[i + K - 1] - B[i - 1]);

		maxn = max(maxn, E1);

		maxn = max(maxn, E1 + A[i + K - 1] - A[i - 1]);

	}

	cout << maxn << endl;

	return 0;

}