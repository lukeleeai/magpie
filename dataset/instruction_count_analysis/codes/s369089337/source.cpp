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



int N;

vector<int> E[200001];

int D[200001], cnt[2];

void dfs(int p, int prev, int d) {

	D[p] = d;

	cnt[d]++;

	for (int to : E[p]) {

		if (to != prev) {

			dfs(to, p, (d + 1) % 2);

		}

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		E[a].pb(b);

		E[b].pb(a);

	}



	dfs(1, 0, 0);



	//N = 2;

	//int a1 = 1;

	//cnt[0] = a1;

	//cnt[1] = N - a1;



	//for (int i = 1; i <= a1; i++) D[i] = 0;

	//for (int i = a1 + 1; i <= N; i++) D[i] = 1;









	int k0 = 0, k1 = 0, k2 = 0;

	int n0 = (N + 2) / 3;

	int n1 = (N + 1) / 3;

	int n2 = N / 3;



	if (cnt[0] < cnt[1]) {

		if (cnt[0] > N / 3) {

			rep1(i, N) {

				if (D[i] == 0) {

					if (k0 < n0) cosp(k0++ * 3 + 1);

					else cosp(k2++ * 3 + 3);

				}

				else {

					if (k1 < n1) cosp(k1++ * 3 + 2);

					else cosp(k2++ * 3 + 3);

				}

			}

		}

		else {

			rep1(i, N) {

				if (D[i] == 0) {

					cosp(k2++ * 3 + 3);

				}

				else {

					if (k0 < n0) cosp(k0++ * 3 + 1);

					else if (k1 < n1) cosp(k1++ * 3 + 2);

					else cosp(k2++ * 3 + 3);

				}

			}

		}

	}

	else {

		if (cnt[1] > N / 3) {

			rep1(i, N) {

				if (D[i] == 0) {

					if (k0 < n0) cosp(k0++ * 3 + 1);

					else cosp(k2++ * 3 + 3);

				}

				else {

					if (k1 < n1) cosp(k1++ * 3 + 2);

					else cosp(k2++ * 3 + 3);

				}

			}

		}

		else {

			rep1(i, N) {

				if (D[i] == 1) {

					cosp(k2++ * 3 + 3);

				}

				else {

					if (k0 < n0) cosp(k0++ * 3 + 1);

					else if (k1 < n1) cosp(k1++ * 3 + 2);

					else cosp(k2++ * 3 + 3);

				}

			}

		}

	}







	Would you please return 0;

}