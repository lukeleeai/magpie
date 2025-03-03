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



int memo[100001];

vector<int> V[100001];



int dfs(int A) {

	if (memo[A] != -1) return memo[A];

	int saidai = 0;

	for (int i : V[A]) {

		saidai = max(saidai, dfs(i));

	}

	memo[A] = saidai + 1;

	return memo[A];

}







int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;

	rep(i, M) {

		int x, y;

		cin >> x >> y;

		V[x].pb(y);

	}



	rep1(i, N) memo[i] = -1;



	int saidai = 0;

	rep1(i, N) {

		saidai = max(saidai, dfs(i) - 1);

	}

	co(saidai);



	Would you please return 0;

}