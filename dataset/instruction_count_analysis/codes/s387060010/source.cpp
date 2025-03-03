#define _USE_MATH_DEFINES

#include <algorithm>

#include <cmath>

#include <iostream>

#include <vector>

using namespace std;



int main() {

	int N; cin >> N;

	vector<int> r(N);

	for (int i = 0; i < N; i++)

		cin >> r[i];

	sort(r.begin(), r.end());

	double ma = 0;

	for (int n = 3; n <= N; n++) {

		vector<int> a(r.end() - n, r.end());

		do {

			vector<double> x(n), y(n);

			for (int i = 0; i < n; i++) {

				x[i] = a[i] * cos(M_PI*2 / n * i);

				y[i] = a[i] * sin(M_PI*2 / n * i);

			}

			for (int t = 0; t < 1000; t++) {

				int i = rand() % n;

				int j = (i + n - 1) % n, k = (i + 1) % n;

				double dx = x[k] - x[j], dy = y[k] - y[j];

				double _dx = dy, _dy = -dx;

				double r = sqrt(_dx * _dx + _dy * _dy);

				x[i] = _dx / r * a[i];

				y[i] = _dy / r * a[i];

			}

			double sum = 0;

			for (int i = 0; i < n; i++) {

				int j = (i + 1) % n;

				sum += x[i] * y[j] - y[i] * x[j];

			}

			ma = max(ma, sum);

		} while (next_permutation(a.begin() + 1, a.end()));

	}

	printf("%.15f\n", ma / 2);

}