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



	

	int N, M;

	cin >> N >> M;



	int A[101][101] = {};

	rep1(i, 100) {

		rep1(ii, 100) {

			if (i != ii) A[i][ii] = 10000000;

		}

	}



	rep(i, M) {

		int a, b, c;

		cin >> a >> b >> c;



		A[a][b] = c;

		A[b][a] = c;

	}



	int B[101][101] = {};

	rep1(k, N) {

		rep1(i, N) {

			rep1(j, N) {

				if (A[i][k] + A[k][j] < A[i][j]) {

					B[i][j] = 1;

					A[i][j] = A[i][k] + A[k][j];

				}

			}

		}

	}



	int goukei = 0;

	rep1(i, N) {

		rep1(ii, N) {

			if (B[i][ii]) goukei++;

		}

	}

	int hennmax = N * (N - 1) / 2;



	co(goukei / 2 + M - hennmax);



	Would you please return 0;

}