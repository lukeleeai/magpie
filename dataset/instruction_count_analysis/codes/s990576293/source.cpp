#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int main() {

	int N;

	cin >> N;

	vector<long long> left(N), right(N);

	for (int i = 0; i < N; ++i) cin >> left[i] >> right[i];

	sort(left.begin(), left.end(), greater<long long>());

	sort(right.begin(), right.end());

	long long res = 0, tmp = 0;



	// left スタート

	tmp = 0;

	for (int i = 0; i < N; ++i) {

		tmp += left[i]; res = max(res, tmp);

		tmp -= right[i]; res = max(res, tmp);

	}



	// right スタート

	tmp = 0;

	for (int i = 0; i < N; ++i) {

		tmp -= right[i]; res = max(res, tmp);

		tmp += left[i]; res = max(res, tmp);

	}



	cout << res * 2 << endl;

}