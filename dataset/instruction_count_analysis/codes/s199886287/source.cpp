#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<cstring>

#include<algorithm>



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



const int CM = 1 << 17, CL = 12;

char cn[CM + CL], * ci = cn + CL, * owa = cn + CM, ct;

const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;



int kari[400010], *tmp;

void pakuri_sort(int N, int A[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(cn + CL, 1, CM, stdin);

	int N = 0, K = 0;

	while ((ct = *ci++) >= '0') N = N * 10 + ct - '0';

	while ((ct = *ci++) >= '0') K = K * 10 + ct - '0';



	int* A = kari + 2, *B = kari + N + 3;

	tmp = kari + N + 4;

	const int mod = 1e9 + 7;

	rep(i, N) {

		if (ci - owa > 0) {

			memcpy(cn, owa, CL);

			ci -= CM;

			fread(cn + CL, 1, CM, stdin);

		}

		if (*ci == '-') {

			ci++;

			ll tmp = *(ll*)ci;

			if ((tmp & ma0) ^ ma0) {

				int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

				tmp = tmp << dig & ma1;

				tmp = tmp * 10 + (tmp >> 8) & ma2;

				tmp = tmp * 100 + (tmp >> 16) & ma3;

				tmp = tmp * 10000 + (tmp >> 32) & ma4;

				ci += (72 - dig >> 3);

			}

			else {

				tmp = tmp & ma1;

				tmp = tmp * 10 + (tmp >> 8) & ma2;

				tmp = tmp * 100 + (tmp >> 16) & ma3;

				tmp = tmp * 10000 + (tmp >> 32) & ma4;

				ci += 8;

				if ((ct = *ci++) >= '0') {

					tmp = tmp * 10 + ct - '0';

					if (*ci++ == '0') {

						tmp = tmp * 10;

						ci++;

					}

				}

			}

			*B-- = tmp;

		}

		else {

			ll tmp = *(ll*)ci;

			if ((tmp & ma0) ^ ma0) {

				int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

				tmp = tmp << dig & ma1;

				tmp = tmp * 10 + (tmp >> 8) & ma2;

				tmp = tmp * 100 + (tmp >> 16) & ma3;

				tmp = tmp * 10000 + (tmp >> 32) & ma4;

				ci += (72 - dig >> 3);

			}

			else {

				tmp = tmp & ma1;

				tmp = tmp * 10 + (tmp >> 8) & ma2;

				tmp = tmp * 100 + (tmp >> 16) & ma3;

				tmp = tmp * 10000 + (tmp >> 32) & ma4;

				ci += 8;

				if ((ct = *ci++) >= '0') {

					tmp = tmp * 10 + ct - '0';

					if (*ci++ == '0') {

						tmp = tmp * 10;

						ci++;

					}

				}

			}

			*A++ = tmp;

		}

	}

	int fu = kari + N + 3 - B;

	int sei = A - kari - 2;

	A = kari + 2;

	B++;



	if (N == K) {

		ll kotae = 1;

		rep(i, sei) kotae = kotae * A[i] % mod;

		rep(i, fu) kotae = kotae * (mod - B[i]) % mod;

		printf("%lld\n", (kotae + mod) % mod);

		return 0;

	}

	pakuri_sort(sei, A);

	pakuri_sort(fu, B);



	if (fu == N) {

		ll kotae = 1;

		if (K % 2) {

			rep(i, K) kotae = kotae * (mod - B[i]) % mod;

		}

		else {

			for (int i = N - 1; i > N - 1 - K; i--) kotae = kotae * (mod - B[i]) % mod;

		}

		printf("%lld\n", (kotae + mod) % mod);

		return 0;

	}



	ll kotae = 1;

	sei--;

	fu--;

	if (K % 2) kotae = A[sei--];



	ll a = (ll)A[sei] * A[sei - 1];

	ll b = (ll)B[fu] * B[fu - 1];



	rep(i, K / 2) {

		if (a >= b) {

			kotae = kotae * (a % mod) % mod;

			sei -= 2;

			a = (ll)A[sei] * A[sei - 1];

		}

		else {

			kotae = kotae * (ll(mod - B[fu]) * (mod - B[fu - 1]) % mod) % mod;

			fu -= 2;

			b = (ll)B[fu] * B[fu - 1];

		}

	}



	printf("%lld\n", (kotae + mod) % mod);







	Would you please return 0;

}