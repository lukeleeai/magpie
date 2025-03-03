#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

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



const int cm = 1 << 15, inf = 1e9;

char cn[cm], * ci = cn, ct;

bool kotae[100][100];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(cn, 1, cm, stdin);



	int N = 0, M = 0;

	while ((ct = *ci++) >= '0') N = N * 10 + ct - '0';

	while ((ct = *ci++) >= '0') M = M * 10 + ct - '0';

	

	int E[100][100];

	rep(j, N) rep(i, j) E[i][j] = inf;



	rep(i, M) {

		int a = 0, b = 0, c = 0;

		while ((ct = *ci++) >= '0') a = a * 10 + ct - '0';

		while ((ct = *ci++) >= '0') b = b * 10 + ct - '0';

		while ((ct = *ci++) >= '0') c = c * 10 + ct - '0';

		a--;

		b--;

		E[a][b] = c;

		E[b][a] = c;

	}



	rep(k, N) {

		rep(j, k) {

			rep(i, j) {

				if (E[i][j] > E[i][k] + E[j][k]) {

					E[i][j] = E[i][k] + E[j][k];

					kotae[i][j] = 1;

				}

			}

		}

		for (int j = k + 1; j < N; j++) {

			rep(i, k) {

				if (E[i][j] > E[i][k] + E[k][j]) {

					E[i][j] = E[i][k] + E[k][j];

					kotae[i][j] = 1;

				}

			}

			for (int i = k + 1; i < j; i++) {

				if (E[i][j] > E[k][i] + E[k][j]) {

					E[i][j] = E[k][i] + E[k][j];

					kotae[i][j] = 1;

				}

			}

		}

	}



	int kazu = 0;

	rep(j, N) rep(i, N) kazu += kotae[i][j];



	printf("%d", kazu - N * (N - 1) / 2 + M);



	Would you please return 0;

}