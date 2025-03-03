#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

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





	int N;

	cin >> N;



	ll kotae = 0;

	rep1(i, N) {

		kotae += i * ll(i + 1) / 2;

	}



	rep(i, N - 1) {

		int u, v;

		cin >> u >> v;

		if (u > v) swap(u, v);



		kotae -= ll(u) * (N - v + 1);





	}

	co(kotae);









	Would you please return 0;

}