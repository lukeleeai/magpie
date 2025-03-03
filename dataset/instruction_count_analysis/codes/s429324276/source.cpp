#include <stdio.h>

#include <algorithm>

#include <string>

#include <vector>

#include <numeric>

#include<queue>



const int mod = 1000000007;

//const int mod = 998244353;



class Matrix {

	int N;

	long long **d;

public:

	Matrix(int N) :N(N) {

		d = new long long*[N];

		for (int i = 0; i < N; i++) {

			d[i] = new long long[N] {};

		}

	}

	void set(long long** o) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				d[i][j] = o[i][j];

			}

		}

	}

	void identity() {

		for (int i = 0; i < N; i++)d[i][i] = 1;

	}



	~Matrix() {

		for (int i = 0; i < N; i++) {

			delete[] d[i];

		}

		delete[] d;

	}

	long long* operator[](int x) const {

		return d[x];

	}

	Matrix& operator*=(const Matrix& o) {

		Matrix temp(N);

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				for (int k = 0; k < N; k++) {

					temp[i][j] += d[i][k] * o[k][j];

					temp[i][j] %= mod;

				}

			}

		}

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				d[i][j] = temp[i][j];

			}

		}

		return *this;

	}

	long long* operator*(long long* v) {

		long long* res = new long long[N] {};

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				res[i] += d[i][j] * v[j];

			}

		}

		return res;

	}

	void print() {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				printf("%lld ", d[i][j]);

			}

			printf("\n");

		}

	}

};



int main() {

	int N;

	long long K;

	scanf("%d %lld", &N, &K);

	long long **G = new long long*[N];

	for (int i = 0; i < N; i++) {

		G[i] = new long long[N];

	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			scanf("%lld", G[i] + j);

		}

	}

	Matrix g(N);

	g.set(G);

	Matrix r(N);

	r.identity();

	while (K != 0) {

		if (K & 1) {

			r *= g;

		}

		K >>= 1;

		g *= g;

	}

	long long res = 0;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {

		res += r[i][j];

		res %= mod;

	}

	printf("%lld", res);

	return 0;

}
