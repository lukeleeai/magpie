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



	int A[1001][1000];

	rep1(i, N) {

		rep(j, N - 1) cin >> A[i][j];

		A[i][N - 1] = 0;

	}



	int k[1001] = {}, k2[1001] = {};

	vector<int> V;

	rep1(i, N) V.pb(i);



	int kotae = 0;

	while (V.size()) {

		kotae++;

		vector<int> kari;

		for (auto v : V) {

			if (k2[v] < kotae) {

				int a = A[v][k[v]];

				if (A[a][k[a]] == v) {

					kari.pb(v);

					k2[v] = kotae;

					kari.pb(a);

					k2[a] = kotae;

				}

			}

		}

		swap(V, kari);

		for (auto v : V) k[v]++;

	}



	int OK = 1;

	rep1(i, N) if (k[i] != N - 1) OK = 0;

	if (OK) co(kotae - 1);

	else co(-1);



	Would you please return 0;

}