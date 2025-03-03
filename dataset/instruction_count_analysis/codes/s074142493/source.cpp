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



//ぜんぜんわからん

ll gcd(ll A, ll B) {

	if (A == 0) return B;

	return gcd(B % A, A);

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;



	int A[100000];

	rep(i, N) cin >> A[i];



	ll lcm = A[0];



	bool dame = 0;

	rep1(i, N - 1) {

		ll g = gcd(lcm, ll(A[i]));

		lcm = lcm / g * A[i];

		if (lcm > 2e9) {

			dame = 1;

			break;

		}

	}



	if (dame) co(0);

	else {

		bool guusuu = 0;

		rep(i, N) {

			if (lcm / A[i] % 2 == 0) guusuu = 1;

		}

		if (guusuu) co(0);

		else {

			ll kotae = (lcm / 2 + M) / lcm;

			co(kotae);

		}

	}



	Would you please return 0;

}