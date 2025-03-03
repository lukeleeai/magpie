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





	int X, Y, A, B, C;

	cin >> X >> Y >> A >> B >> C;



	int a[100000], b[100000], c[100000];

	rep(i, A) cin >> a[i];

	rep(i, B) cin >> b[i];

	rep(i, C) cin >> c[i];



	sort(a, a + A);

	reverse(a, a + A);

	sort(b, b + B);

	reverse(b, b + B);

	sort(c, c + C);

	reverse(c, c + C);



	ll kotae = 0;



	ll ctmp = 0;

	ll abtmp = 0;

	rep(i, X) abtmp += a[i];

	rep(i, Y) abtmp += b[i];

	int aa = X - 1;

	int bb = Y - 1;

	chmax(kotae, ctmp + abtmp);

	rep(i, min(C, X + Y)) {

		ctmp += c[i];

		if (aa == -1) {

			abtmp -= b[bb--];

		}

		else if (bb == -1) {

			abtmp -= a[aa--];

		}

		else {

			if (a[aa] < b[bb]) {

				abtmp -= a[aa--];

			}

			else abtmp -= b[bb--];

		}

		chmax(kotae, ctmp + abtmp);

	}

	co(kotae);



	Would you please return 0;

}