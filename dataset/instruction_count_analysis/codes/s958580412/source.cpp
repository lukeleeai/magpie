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





	int n, K;

	cin >> n >> K;



	vector<ll> A, B;

	rep(i, n) {

		int a;

		cin >> a;



		if (a >= 0) A.pb(a);

		else B.pb(-a);

	}

	sort(A.begin(), A.end());

	reverse(A.begin(), A.end());

	sort(B.begin(), B.end());

	reverse(B.begin(), B.end());



	int N = A.size();

	int M = B.size();



	ll kari = 1;

	int ikeru = 1;

	int p = 0, q = 0;



	if (K % 2) {

		if (N == 0) {

			ikeru = 0;

		}

		else {

			kari = A[0];

			p = 1;

		}

	}



	while (ikeru && p + q < K) {

		if (p + 2 > N && q + 2 > M) {

			ikeru = 0;

			break;

		}

		if (p + 2 > N) {

			kari = kari * B[q] % mod * B[q + 1] % mod;

			q += 2;

		}

		else if (q + 2 > M) {

			kari = kari * A[p] % mod * A[p + 1] % mod;

			p += 2;

		}

		else {

			ll tmp1 = A[p] * (ll)A[p + 1];

			ll tmp2 = B[q] * (ll)B[q + 1];

			if (tmp1 > tmp2) {

				kari = kari * A[p] % mod * A[p + 1] % mod;

				p += 2;

			}

			else {

				kari = kari * B[q] % mod * B[q + 1] % mod;

				q += 2;

			}

		}

	}



	if (p + q == K && ikeru) {

		co(kari);

		return 0;

	}



	reverse(A.begin(), A.end());

	reverse(B.begin(), B.end());



	p = 0;

	q = 0;

	kari = 1;

	while (p + q < K) {

		if (p == N) {

			kari = kari * B[q] % mod;

			q += 1;

		}

		else if (q == M) {

			kari = kari * A[p] % mod;

			p += 1;

		}

		else {

			if (A[p] < B[q]) {

				kari = kari * A[p] % mod;

				p += 1;

			}

			else {

				kari = kari * B[q] % mod;

				q += 1;

			}

		}

	}

	co((mod - kari) % mod);





	Would you please return 0;

}