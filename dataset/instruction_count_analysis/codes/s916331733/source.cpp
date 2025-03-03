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



const ll AS = 10200;

ll dat[2 * AS];

ll query(int l, int r) {

	ll ret = -2e18;

	for (l += AS, r += AS; l < r; l >>= 1, r >>= 1) {

		if (l & 1) chmax(ret, dat[l++]);

		if (r & 1) chmax(ret, dat[--r]);

	}

	return ret;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, K;

	cin >> N >> K;

	int P[5000], C[5000];

	rep(i, N) {

		cin >> P[i];

		P[i]--;

	}

	rep(i, N) {

		cin >> C[i];

	}



	ll kotae = -2e18;

	int yatta[5000] = {};

	rep(i, N) if (!yatta[i]) {

		int L = 0;

		auto kari = dat + AS;

		kari[0] = 0;

		int j = i;

		while (!yatta[j]) {

			yatta[j] = 1;

			kari[L + 1] = kari[L] + C[j];

			L++;

			j = P[j];

		}

		ll hue = kari[L];

		for (int j = L + 1; j <= L + L; j++) {

			kari[j] = kari[j - L] + hue;

		}

		for (int j = AS - 1; j > 0; j--) {

			dat[j] = max(dat[j << 1], dat[j << 1 | 1]);

		}

		ll amari = K % L;

		ll wari = K / L;



		if (hue > 0) {

			rep1(j, L) {

				ll hajimari = kari[j - 1];

				chmax(kotae, hue * wari + query(j, j + amari) - hajimari);

			}

			if (wari > 0) {

				rep1(j, L) {

					ll hajimari = kari[j - 1];

					chmax(kotae, hue * (wari - 1) + query(j + amari, j + L) - hajimari);

				}

			}

		}

		else {

			rep1(j, L) {

				ll hajimari = kari[j - 1];

				chmax(kotae, query(j, j + min(K, L)) - hajimari);

			}

		}

	}



	co(kotae);





	Would you please return 0;

}