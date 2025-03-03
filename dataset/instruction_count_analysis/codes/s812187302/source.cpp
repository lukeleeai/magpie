#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



int dp1[3001][3000], dp2[3001][3000];



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, T;

	cin >> N >> T;

	int A[3000], B[3000];

	rep(i, N) cin >> A[i] >> B[i];





	rep(i, N + 1) rep(j, T) dp1[i][j] = -1e9;

	dp1[0][0] = 0;

	rep(i, N) {

		rep(j, T) {

			if (dp1[i][j] >= 0) {

				if (j + A[i] < T) chmax(dp1[i + 1][j + A[i]], dp1[i][j] + B[i]);

				chmax(dp1[i + 1][j], dp1[i][j]);

			}

		}

	}

	rep(i, N + 1) rep(j, T) dp2[i][j] = -1e9;

	dp2[N][0] = 0;

	for (int i = N - 1; i >= 0; i--) {

		rep(j, T) {

			if (dp2[i + 1][j] >= 0) {

				if (j + A[i] < T) chmax(dp2[i][j + A[i]], dp2[i + 1][j] + B[i]);

				chmax(dp2[i][j], dp2[i + 1][j]);

			}

		}

	}



	rep(i, N + 1) rep1(j, T - 1) chmax(dp1[i][j], dp1[i][j - 1]);

	rep(i, N + 1) rep1(j, T - 1) chmax(dp2[i][j], dp2[i][j - 1]);



	int saidai = 0;

	rep(i, N) {

		rep(j, T) {

			chmax(saidai, dp1[i][j] + dp2[i + 1][T - j - 1] + B[i]);

		}

	}

	co(saidai);



	Would you please return 0;

}