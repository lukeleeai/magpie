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

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	ll a[100000];

	ll goukei = 0;

	rep(i, N) {

		cin >> a[i];

		goukei ^= a[i];

	}



	int M = 60;

	bool A[100000][60] = {};

	rep(i, N) {

		rep(j, M) {

			A[i][j] = a[i] >> j & 1;

		}

	}



	int r = 0;

	for (int i = M - 1; i >= 0; i--) {

		if (!(goukei >> i & 1)) {

			for (int j = r; j < N; j++) {

				if (A[j][i]) {

					rep(k, M) swap(A[r][k], A[j][k]);



					for (int j = r + 1; j < N; j++) {

						if (A[j][i]) {

							rep(k, M) A[j][k] ^= A[r][k];

						}

					}

					if (!A[0][i]) {

						rep(k, M) A[0][k] ^= A[r][k];

					}

					r++;

					break;

				}

			}

		}

	}



	ll kotae = 0;

	rep(i, M) {

		if (!(goukei >> i & 1)) {

			if (A[0][i]) {

				kotae += 1ll << (i + 1);

			}

		}

		else {

			kotae += 1ll << i;

		}

	}

	co(kotae);







	Would you please return 0;

}