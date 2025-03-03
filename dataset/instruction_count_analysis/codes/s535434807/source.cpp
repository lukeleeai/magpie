#pragma GCC optimize ("O3")

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



	__int128 kotae = 1;



	int zero = 0;

	int yabai = 0;

	rep(i, N) {

		ll a;

		cin >> a;



		kotae = kotae * a;



		if (kotae > ll(1e18)) {

		

			yabai = 1;

		}

		if (a == 0) {

			zero = 1;

		}

	}



	if (zero) co(0);

	else if (yabai) {

		co(-1);

	}

	else co(ll(kotae));





	Would you please return 0;

}