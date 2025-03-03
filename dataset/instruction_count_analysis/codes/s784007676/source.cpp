#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>

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



char S[3][2002];

int L[3];

bool mita[3][3][4020], dame[3][3][4020];

inline bool DAME(int i, int j, int k) {

	if (mita[i][j][k]) return dame[i][j][k];

	mita[i][j][k] = 1;

	auto si = S[i] + k;

	auto sj = S[j];

	rep(x, min(L[i] - k, L[j])) {

		if (si[x] != '?' && sj[x] != '?' && si[x] != sj[x]) {

			return dame[i][j][k] = 1;

		}

	}

	return 0;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	rep(i, 3) scanf("%s", S[i]);

	rep(i, 3) L[i] = strlen(S[i]);



	int P[3] = { 0,1,2 };

	int saishou = 6000;

	rep(x, 6) {

		int i = P[0];

		int j = P[1];

		int k = P[2];

		rep(p, L[i] + 1) {

			int tmp = max(L[i], L[j] + p);

			if (tmp >= saishou) break;

			if (!DAME(i, j, p)) {

				rep(q, saishou - L[k] - p) {

					if (!DAME(j, k, q) && !DAME(i, k, p + q)) {

						saishou = max(tmp, L[k] + p + q);

						break;

					}

				}

			}

		}

		next_permutation(P, P + 3);

	}



	printf("%d", saishou);





	Would you please return 0;

}