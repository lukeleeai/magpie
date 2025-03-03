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



ll mod = 1e9 + 7;

ll modpow(ll A, ll B) {

	if (B == 0) return 1;

	if (B % 2) return A * modpow(A, B - 1) % mod;

	ll half = modpow(A, B / 2);

	return half * half % mod;

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, A, B, C, D;

	cin >> N >> A >> B >> C >> D;



	ll F[1001], FI[1001];

	F[0] = 1;

	rep1(i, 1000) {

		F[i] = F[i - 1] * i % mod;

	}

	FI[1000] = modpow(F[1000], mod - 2);

	for (int i = 1000; i > 0; i--) {

		FI[i - 1] = FI[i] * i % mod;

	}



	ll dp[1001][1001] = {};

	dp[0][0] = F[N];

	rep(i, N) {

		rep(j, N) {

			if (dp[i][j]) {

				dp[i + 1][j] += dp[i][j];

				dp[i + 1][j] %= mod;

				if (A <= i + 1 && i + 1 <= B) {

					for (int k = C; k <= D; k++) {

						int kari = j + k * (i + 1);

						if (kari <= N) {

							dp[i + 1][kari] += dp[i][j] * modpow(FI[i + 1], k) % mod * FI[k] % mod;

							dp[i + 1][kari] %= mod;

						}

						else break;

					}

				}

			}

		}

	}

	ll kotae = 0;

	rep(i, N + 1) {

		kotae += dp[i][N];

		kotae %= mod;

	}

	co(kotae);



	Would you please return 0;

}