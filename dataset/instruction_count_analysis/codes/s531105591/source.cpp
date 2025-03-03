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



int N;

int C[200001];

int X[200001];

vector<int> E[200001];

void dfs(int p, int prev, int c) {

	int k = c + X[p];

	C[p] = k;

	for (int to : E[p]) {

		if (to != prev) dfs(to, p, k);

	}

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, Q;

	cin >> N >> Q;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		E[a].pb(b);

		E[b].pb(a);

	}

	rep(i, Q) {

		int p, x;

		cin >> p >> x;

		X[p] += x;

	}

	dfs(1, 0, 0);



	rep1(i, N) cosp(C[i]);



	Would you please return 0;

}