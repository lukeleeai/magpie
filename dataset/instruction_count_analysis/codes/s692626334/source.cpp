#include <cstdio>

#include <cstring>



inline int gcd(int a, int b) {

	while (a != 0) {

		int t = b % a;

		b = a;

		a = t;

	}

	return b;

}



inline int abs(int x) {

	return x < 0 ? -x : x;

}



struct Frac {

	int a, b;

	Frac() : a(1), b(1) {}

	Frac(int a, int b) : a(a), b(b) {

		reduce();

	}

	void reduce() {

		int g = gcd(a, b);

		a /= g;

		b /= g;

	}

	bool operator < (const Frac& f) const {

		return (long long)a * f.b < (long long)b * f.a;

	}

};



inline void checkMin(Frac& ret, const Frac& val) {

	if (val < ret) {

		ret = val;

	}

}



inline void checkMax(Frac& ret, const Frac& val) {

	if (ret < val) {

		ret = val;

	}

}



int n;

int a[100000];

Frac dp[2][200001];



int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {

		scanf("%d", &a[i]);

	}

	for (int i = 1; i <= a[0] * 2; ++i) {

		dp[0][i] = Frac(0, 1);

	}

	for (int i = 0; i < n; ++i) {

		int lim = i + 1 == n ? 0 : a[i + 1] * 2;

		for (int j = 1; j <= a[i] * 2; ++j) {

			checkMax(dp[i % 2][j], Frac(abs(j - a[i]), a[i]));

			for (int k = j; k <= lim; k += j) {

				checkMin(dp[1 - i % 2][k], dp[i % 2][j]);

			}

		}

	}

	Frac res;

	for (int i = 1; i <= a[n - 1] * 2; ++i) {

		checkMin(res, dp[(n - 1) % 2][i]);

	}

	printf("%.13lf\n", (double)res.a / res.b);

	return 0;

}