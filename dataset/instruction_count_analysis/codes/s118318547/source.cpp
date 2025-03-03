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



int N, K;

int kotae = 0;

vector<int> E[100001];

int dfs(int A, int D) {

	int d = 1;

	for (int to : E[A]) {

		d = max(d, dfs(to, D + 1) + 1);

	}

	if (d >= K && D > 1) {

		kotae++;

		return 0;

	}

	else return d;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N >> K;



	rep1(i, N) {

		int a;

		cin >> a;

		if (i != 1) E[a].pb(i);

		else if (a != 1) kotae++;

	}



	dfs(1, 0);

	co(kotae);



	Would you please return 0;

}