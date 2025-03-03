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

	int A[701][701] = {};

	rep(i, M) {

		int a, b;

		cin >> a >> b;

		A[a][b] = 1;

		A[b][a] = 1;

	}

	vector<int> E[701];

	rep1(i, N) rep1(j, N) {

		if (A[i][j] == 0 && i != j) E[i].pb(j);

	}



	vector<pair<int, int>> V;









	int dame = 0;

	int tukatta[701] = {};



	rep1(q, N) {

		if (tukatta[q] == 0) {

			tukatta[q] = 1;

			int X = 1;

			int XX[701] = {};

			rep1(i, N) XX[i] = 1;

			int Y = 0;

			int YY[701] = {};

			rep1(i, N) YY[i] = 1;

			rep1(i, N) XX[i] &= A[q][i];



			vector<pair<int, int>> que;

			que.pb(mp(q, 0));

			while (que.size()) {

				vector<pair<int, int>> que2;

				for (auto p : que) {

					int i = p.first;

					for(int j : E[i]) {

						if (tukatta[j] == 0) {

							tukatta[j] = 1;

							que2.pb(mp(j, p.second ^ 1));

							if (p.second == 0) {

								if (YY[j] == 0) dame = 1;

								Y++;

								rep1(k, N) YY[k] &= A[j][k];

							}

							else {

								if (XX[j] == 0) dame = 1;

								X++;

								rep1(k, N) XX[k] &= A[j][k];

							}

						}

					}

				}

				que = que2;

			}

			V.pb(mp(X, Y));



			cesp(X);

			ce(Y);

		}

	}



	set<int> dp;

	dp.insert(0);

	for (auto p : V) {

		set<int> dp2;

		for (int i : dp) {

			dp2.insert(i + p.first);

			dp2.insert(i + p.second);

		}

		dp = dp2;

	}





	if (dame) {

		co(-1);

	}

	else {

		int saishou = 1e9;

		for (auto i : dp) {

			saishou = min(saishou, abs(N - 2 * i));

		}

		int X = (N + saishou) / 2;

		int Y = (N - saishou) / 2;

		int kotae = X * (X - 1) / 2 + Y * (Y - 1) / 2;

		co(kotae);

	}



	Would you please return 0;

}