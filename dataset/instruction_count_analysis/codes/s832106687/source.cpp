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





	int N;

	cin >> N;

	char c;



	ll dp0 = 0;

	ll dp1 = -1e18;

	cin >> dp0;

	bool hajimete = 0;

	ll purasu = 0;



	rep(i, N - 1) {

		int a;

		cin >> c >> a;



		if (hajimete == 0) {

			if (c == '+') {

				dp0 += a;

			}

			else {

				hajimete = 1;

				dp0 -= a;

			}

		}

		else {

			if (c == '+') {

				purasu += a;

			}

			else {

				dp1 = max(dp1 + purasu + a, dp0 + a - purasu);

				dp0 += purasu - a;

				purasu = 0;

			}

		}

	}

	co(max(dp0, dp1) + purasu);



	Would you please return 0;

}