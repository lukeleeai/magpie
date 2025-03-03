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





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int X, K;

	cin >> X >> K;

	int r[100002];

	rep1(i, K) cin >> r[i];

	r[0] = 0;

	r[K + 1] = 2e9;



	int L = 0;

	int R = X;

	int takasa = 0;

	int katamuki = -1;

	int *ri = r;



	int Q;

	cin >> Q;

	rep(i, Q) {

		int t, a;

		cin >> t >> a;

		

		while (t > *(ri + 1)) {

			takasa += katamuki * (*(ri + 1) - *ri);

			if (katamuki < 0) {

				L -= min(0, takasa + L);

				R -= min(0, takasa + R);

			}

			else {

				L -= max(0, takasa + L - X);

				R -= max(0, takasa + R - X);

			}

			ri++;

			katamuki *= -1;

		}

		chmax(a, L);

		chmin(a, R);

		a += takasa + katamuki * (t - *ri);

		chmax(a, 0);

		chmin(a, X);

		co(a);

	}



	Would you please return 0;

}