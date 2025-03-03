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



int DT[100001], DA[100001];

vector<int> E[100001];

void dfsT(int A, int d) {

	if (DT[A]) return;

	DT[A] = d;

	for (int to : E[A]) {

		dfsT(to, d + 1);

	}

}

void dfsA(int A, int d) {

	if (DA[A]) return;

	DA[A] = d;

	for (int to : E[A]) {

		dfsA(to, d + 1);

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int u, v;

	cin >> u >> v;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		E[a].pb(b);

		E[b].pb(a);

	}



	dfsT(u, 1);

	dfsA(v, 1);



	int saidai = -1;

	rep1(i, N) {

		if (DT[i] < DA[i]) chmax(saidai, DA[i]);

	}



	//int kei = DT[1] + DA[1];

	//if (kei % 2) {

	//	co(saidai - 2);

	//}

	//else {

	//}

	if (saidai - 2 <= 0) co(0);

	else co(saidai - 2);



	Would you please return 0;

}