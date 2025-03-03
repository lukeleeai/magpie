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

	vector<int> IE[100001];

	int num = 1;

	int topo[100001], jisuu[100001] = {};

	rep(i, N + M - 1) {

		int a, b;

		cin >> a >> b;

		IE[b].pb(a);

		jisuu[a]++;

	}



	stack<int> ST;

	rep1(i, N) {

		if(!jisuu[i])ST.push(i);

	}

	while (ST.size()) {

		int k = ST.top();

		ST.pop();

		topo[k] = num++;

		for (int u : IE[k]) {

			jisuu[u]--;

			if (!jisuu[u]) ST.push(u);

		}

	}



	rep1(i, N) {

		int kotae = 0;

		int saishou = 1e9;

		if (topo[i] == N) kotae = 0;

		else {

			for (int u : IE[i]) {

				if (saishou > topo[u]) {

					saishou = topo[u];

					kotae = u;

				}

			}

		}

		co(kotae);

	}



	Would you please return 0;

}