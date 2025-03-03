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





	int N, A, B;

	cin >> N >> A >> B;

	ll H[100000];

	rep(i, N) cin >> H[i];



	int L = 1, R = 1e9;



	while (L != R) {

		int half = (L + R) / 2;



		ll damage = 1ll * B * half;

		ll cnt = 0;

		rep(i, N) {

			ll kari = (H[i] - damage + A - B - 1) / (A - B);

			if (kari > 0) {

				cnt += kari;

			}

		}

		if (half >= cnt) R = half;

		else L = half + 1;

	}



	co(L);



	Would you please return 0;

}