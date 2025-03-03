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



vector<int> E[100001];

int kotae[100001];

int Vis[100001];

void sagasu(int P, int D, int C) {

	if (D == 0 && kotae[P] == 0) kotae[P] = C;

	else if (Vis[P] < D) {

		Vis[P] = D;

		if (kotae[P] == 0) kotae[P] = C;

		for (int p : E[P]) {

			sagasu(p, D - 1, C);

		}

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M, Q;

	cin >> N >> M;

	rep(i, M) {

		int a, b;

		cin >> a >> b;

		E[a].pb(b);

		E[b].pb(a);

	}

	cin >> Q;

	int v[100000], d[100000], c[100000];

	rep(i, Q) cin >> v[i] >> d[i] >> c[i];



	for (int i = Q - 1; i >= 0; i--) {

		sagasu(v[i], d[i], c[i]);

	}

	rep1(i, N) {

		co(kotae[i]);

	}



	Would you please return 0;

}