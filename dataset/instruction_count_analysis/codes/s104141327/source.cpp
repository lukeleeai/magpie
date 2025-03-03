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



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	string S[3];

	rep(i, 3) cin >> S[i];

	int L[3];

	rep(i, 3) L[i] = S[i].size();



	bool dame[3][3][4020] = {};

	rep(i, 3) rep(j, 3) if (i != j) {

		rep(k, L[i]) {

			int ok = 1;

			int k2 = min(L[i] - k, L[j]);

			rep(x, k2) {

				if (S[i][k + x] != '?' && S[j][x] != '?' && S[i][k + x] != S[j][x]) {

					ok = 0;

					break;

				}

			}

			if (!ok) dame[i][j][k] = 1;

		}

	}



	int P[3] = { 0,1,2 };

	int saishou = 6000;

	rep(x, 6) {

		int i = P[0];

		int j = P[1];

		int k = P[2];



		rep(p, L[i] + 1) {

			if (!dame[i][j][p]) {

				rep(q, 4010) {

					if (!dame[j][k][q] && !dame[i][k][p + q]) {

						chmin(saishou, max({ L[i], L[j] + p, L[k] + p + q }));

						break;

					}

				}

			}

		}

		next_permutation(P, P + 3);

	}



	co(saishou);





	Would you please return 0;

}