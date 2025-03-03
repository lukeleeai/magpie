#include <vector>

#include <iostream>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

class ModMatrix {

public:

	// ------ Variables ------ //

	int r, c; vector<vector<int> > mat;

	static const int mod = 1000000009;

	// ------ Constructor ------ //

	ModMatrix() : r(0), c(0) {}

	ModMatrix(int r_, int c_) : r(r_), c(c_) { mat = vector<vector<int> >(r_, vector<int>(c_, 0)); }

	// ------ Operator ------ //

	friend bool operator==(const ModMatrix& a, const ModMatrix& b) { return a.mat == b.mat; }

	friend bool operator!=(const ModMatrix& a, const ModMatrix& b) { return a.mat != b.mat; }

	friend ModMatrix operator+(const ModMatrix& a, const ModMatrix& b) {

		if (a.r == b.r && a.c == b.c) {

			ModMatrix c(a);

			for (int i = 0; i < a.r; i++) {

				for (int j = 0; j < a.c; j++) {

					c.mat[i][j] = (c.mat[i][j] + b.mat[i][j]) % ModMatrix::mod;

				}

			}

			return c;

		}

		return ModMatrix();

	}

	friend ModMatrix operator-(const ModMatrix& a, const ModMatrix& b) {

		if (a.r == b.r && a.c == b.c) {

			ModMatrix c(a);

			for (int i = 0; i < a.r; i++) {

				for (int j = 0; j < a.c; j++) {

					c.mat[i][j] = (c.mat[i][j] - b.mat[i][j] + ModMatrix::mod) % ModMatrix::mod;

				}

			}

			return c;

		}

		return ModMatrix();

	}

	friend ModMatrix operator*(const ModMatrix& a, const ModMatrix& b) {

		if (a.c == b.r) {

			ModMatrix c(a.r, b.c);

			for (int i = 0; i < a.r; i++) {

				for (int j = 0; j < b.c; j++) {

					for (int k = 0; k < a.c; k++) {

						c.mat[i][j] = (c.mat[i][j] + 1LL * a.mat[i][k] * b.mat[k][j]) % ModMatrix::mod;

					}

				}

			}

			return c;

		}

		return ModMatrix();

	}

	template<class Type>

	friend ModMatrix operator*(const ModMatrix& a, const Type& b) {

		ModMatrix c(a.r, a.c);

		for (int i = 0; i < a.r; i++) {

			for (int j = 0; j < a.c; j++) {

				c.mat[i][j] = 1LL * c.mat[i][j] * b % ModMatrix::mod;

			}

		}

		return c;

	}

	template<class Type>

	friend ModMatrix operator*(const Type& a, const ModMatrix& b) {

		ModMatrix c(b.r, b.c);

		for (int i = 0; i < b.r; i++) {

			for (int j = 0; j < b.c; j++) {

				c.mat[i][j] = 1LL * c.mat[i][j] * a % ModMatrix::mod;

			}

		}

		return c;

	}

	ModMatrix& operator+=(const ModMatrix& a) {

		if (a.r == r && a.c == c) {

			for (int i = 0; i < r; i++) {

				for (int j = 0; j < c; j++) {

					mat[i][j] = (mat[i][j] + a.mat[i][j]) % mod;

				}

			}

		}

		return *this;

	}

	ModMatrix& operator-=(const ModMatrix& a) {

		if (a.r == r && a.c == c) {

			for (int i = 0; i < r; i++) {

				for (int j = 0; j < c; j++) {

					mat[i][j] = (mat[i][j] - a.mat[i][j] + mod) % mod;

				}

			}

		}

		return *this;

	}

	ModMatrix& operator*=(const ModMatrix& a) {

		if (c == a.r && c == a.c) {

			vector<vector<int> > tmp(r, vector<int>(c));

			for (int i = 0; i < r; i++) {

				for (int j = 0; j < c; j++) {

					for (int k = 0; k < c; k++) {

						tmp[i][j] = (tmp[i][j] + 1LL * mat[i][k] * a.mat[k][j]) % mod;

					}

				}

			}

			for (int i = 0; i < r; i++) {

				for (int j = 0; j < c; j++) {

					mat[i][j] = tmp[i][j];

				}

			}

		}

		return *this;

	}

	template<class Type>ModMatrix& operator*=(const Type& a) {

		for (int i = 0; i < r; i++) {

			for (int j = 0; j < c; j++) {

				mat[i][j] = 1LL * mat[i][j] * c % mod;

			}

		}

		return *this;

	}

};

// ------ Function ------ //

ModMatrix unit(int r) {

	ModMatrix res(r, r);

	for (int i = 0; i < r; i++) {

		res.mat[i][i] = 1;

	}

	return res;

}

ModMatrix power(ModMatrix a, long long b) {

	if (a.r == a.c) {

		ModMatrix res = unit(a.r);

		for (int i = 62; i >= 0; i--) {

			res *= res;

			if (b & (1LL << i)) {

				res *= a;

			}

		}

		return res;

	}

	return ModMatrix();

}

int W, N, C, A[30]; long long H, B[30], R[30], pos, nxt; vector<int> S[30];

int main() {

	while (true) {

		scanf("%d%lld%d", &W, &H, &N);

		if (W == 0 && H == 0 && N == 0) break;

		for (int i = 0; i < N; i++) scanf("%d%lld", &A[i], &B[i]);

		ModMatrix F(W, W), G(W, 1);

		for (int i = 0; i < W; i++) {

			for (int j = 0; j < W; j++) {

				if (-1 <= j - i && j - i <= 1) {

					F.mat[i][j] = 1;

				}

			}

		}

		int c = 0;

		for (int i = 0; i < N; i++) {

			bool flag = true;

			for (int j = 0; j < c; j++) {

				if (R[j] == B[i]) flag = false;

			}

			if (flag) R[c++] = B[i];

		}

		for (int i = 0; i < c; i++) S[i].clear();

		sort(R, R + c);

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < c; j++) {

				if (R[j] == B[i]) {

					S[j].push_back(A[i]);

				}

			}

		}

		G.mat[0][0] = 1;

		pos = 1;

		if (N == 0) nxt = H;

		else nxt = R[0];

		for (int i = 0; i <= c; i++) {

			G = power(F, nxt - pos) * G;

			if (i != c) {

				for (int j = 0; j < S[i].size(); j++) {

					G.mat[S[i][j] - 1][0] = 0;

				}

			}

			pos = nxt;

			if (i + 1 == c) nxt = H;

			else nxt = R[i + 1];

		}

		printf("Case %d: %d\n", ++C, G.mat[W - 1][0]);

	}

	return 0;

}