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



int d = 0;

int D[10002];

int topo[10002];

vector<int> E[10002];

void dfs(int A, int B) {

	if (!D[A]) {

		D[A] = B;

		topo[A] = d;

		d++;

		for (int i : E[A]) {

			dfs(i, B + 1);

		}

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		E[a].pb(b);

		E[b].pb(a);

	}



	int C[10002];

	int goukei = 0;

	int saidai = 0;

	rep(i, N) {

		cin >> C[i];

		goukei += C[i];

		saidai = max(saidai, C[i]);

	}

	sort(C, C + N);

	reverse(C, C + N);



	dfs(1, 1);

	co(goukei - saidai);

	rep1(i, N) {

		cosp(C[topo[i]]);

	}



	Would you please return 0;

}