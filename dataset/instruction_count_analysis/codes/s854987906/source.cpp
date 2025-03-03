#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please



unsigned char D[252004];

bool E[252004];

unsigned int Q[300000];

int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int n = N + 2;

	rep1(i, N) {

		int ij = n * i + 1;

		unsigned char kari = min(i - 1, N - i) + 2;

		unsigned char kari2 = 2;

		rep1(j, N / 2) {

			D[ij++] = min(kari, kari2++);

		}

		if (N % 2 == 0) kari2--;

		for (int j = N / 2 + 1; j <= N; j++) {

			D[ij++] = min(kari, kari2--);

		}

	}



	int kotae = 0;

	rep(k, N * N) {

		int ij;

		cin >> ij;

		ij += (ij - 1) / N * 2 + N + 2;



		kotae += D[ij]--;

		E[ij] = 1;



		int p = 0, q = 0;

		Q[p++] = ij;



		while (p > q) {

			int ij = Q[q++];

			int d =	D[ij] + 1;



			if (D[ij - n] > d - E[ij - n]) {

				D[ij - n] = d - E[ij - n];

				Q[p++] = ij - n;

			}

			if (D[ij + n] > d - E[ij + n]) {

				D[ij + n] = d - E[ij + n];

				Q[p++] = ij + n;

			}

			if (D[ij - 1] > d - E[ij - 1]) {

				D[ij - 1] = d - E[ij - 1];

				Q[p++] = ij - 1;

			}

			if (D[ij + 1] > d - E[ij + 1]) {

				D[ij + 1] = d - E[ij + 1];

				Q[p++] = ij + 1;

			}

		}

	}



	co(kotae - 2 * N * N);







	Would you please return 0;

}