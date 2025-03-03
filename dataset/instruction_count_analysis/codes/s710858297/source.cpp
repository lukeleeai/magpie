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



const int mod = 1e9 + 7;

ll modpow(ll A, ll B) {

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



	int tmp[100001];

	tmp[0] = 1;

	rep1(i, N) tmp[i] = ll(tmp[i - 1]) * i % mod;

	ll fac = tmp[N - 1];

	ll ifac = modpow(tmp[N], mod - 2);

	for (int i = N; i > 0; i--) {

		tmp[i] = tmp[i - 1] * ifac % mod;

		ifac = ifac * i % mod;

	}



	int kei = 0;

	ll kotae = 0;

	int mae;

	cin >> mae;

	rep1(i, N - 1) {

		int tugi;

		cin >> tugi;

		ll X = tugi - mae;

		kei = (kei + tmp[i]) % mod;

		kotae += kei * X % mod;

		mae = tugi;

	}



	co(kotae % mod * fac % mod);







	Would you please return 0;

}