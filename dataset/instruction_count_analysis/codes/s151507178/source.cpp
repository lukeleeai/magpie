//#pragma GCC optimize ("O3")

//#pragma GCC target ("avx2")

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



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N, M;

	cin >> N >> M;



	int H[100001];

	rep1(i, N) cin >> H[i];



	vector<int> E[100001];

	rep(i, M) {

		int a, b;

		cin >> a >> b;



		E[a].pb(b);

		E[b].pb(a);



	}



	int kotae = 0;

	rep1(i, N) {

		int OK = 1;

		rep(j, E[i].size()) {

			if (H[i] <= H[E[i][j]]) OK = 0;

		}

		if (OK) kotae++;

	}



	co(kotae);



	Would you please return 0;

}