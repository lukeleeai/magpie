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



const int mod = 1e9 + 7;

constexpr ll modpow(ll A, ll B) {

	ll kotae = 1;

	while (B > 0) {

		if (B & 1) kotae = kotae * A % mod;

		A = A * A % mod;

		B >>= 1;

	}

	return kotae;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	pair<ll, ll> AB[200200], BA[200200];

	int a0 = 0, b0 = 0;

	int ab00 = 0;

	int ka = 0, kb = 0;

	rep(i, N) {

		ll a, b;

		cin >> a >> b;



		if (a == 0 && b == 0) {

			ab00++;

			continue;

		}

		if (a == 0) {

			a0++;

			continue;

		}

		if (b == 0) {

			b0++;

			continue;

		}



		ll G = gcd(a, b);

		a /= G;

		b /= G;

		if (a < 0) {

			a = -a;

			b = -b;

		}

		if (b > 0) AB[ka++] = { a,b };

		else BA[kb++] = { -b,a };

	}



	ll kotae = 1;

	sort(AB, AB + ka);

	sort(BA, BA + kb);

	BA[kb] = { 2e18, 2e18 };



	pair<ll, ll> mae = AB[0];

	int p = 0;

	int kA = 0;

	rep(i, ka) {

		ll a = AB[i].first;

		ll b = AB[i].second;

		if (mae != AB[i]) {

			int tmp = 0;



			pair<ll, ll> mae2 = BA[p];

			int kB = 0;

			while (p < kb && BA[p] <= mae) {

				if (mae2 != BA[p]) {

					kotae = kotae * modpow(2, kB) % mod;

					mae2 = BA[p];

					kB = 1;

				}

				else kB++;

				p++;

			}



			if (mae == mae2) {

				tmp = kB;

			}

			else {

				kotae = kotae * modpow(2, kB) % mod;

			}



			if (tmp) {

				kotae = kotae * (modpow(2, kA) + modpow(2, kB) - 1) % mod;

			}

			else {

				kotae = kotae * modpow(2, kA) % mod;

			}



			mae = AB[i];

			kA = 1;

		}

		else kA++;

	}



	int tmp = 0;

	pair<ll, ll> mae2 = BA[p];

	int kB = 0;

	while (p < kb) {

		if (mae2 != BA[p]) {

			if (AB[ka - 1] == mae2) {

				tmp = kB;

			}

			else {

				kotae = kotae * modpow(2, kB) % mod;

			}

			mae2 = BA[p];

			kB = 1;

		}

		else kB++;

		p++;

	}



	if (AB[ka - 1] == mae2) {

		tmp = kB;

	}

	else {

		kotae = kotae * modpow(2, kB) % mod;

	}



	if (tmp) {

		kotae = kotae * (modpow(2, kA) + modpow(2, kB) - 1) % mod;

	}

	else {

		kotae = kotae * modpow(2, kA) % mod;

	}



	kotae = kotae * (modpow(2, a0) + modpow(2, b0) - 1) % mod;



	co((kotae - 1 + ab00 + 2 * mod) % mod);



	Would you please return 0;

}