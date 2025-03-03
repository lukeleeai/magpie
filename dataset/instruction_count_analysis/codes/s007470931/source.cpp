#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



//みなさん天才すぎないすか



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline ll getint() {

	ll A = 0;

	if (ci - cn + 24 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	ll kazu[20] = {};

	const int mod = 1e9 + 7;

	const ll m = 1 + (1 << 20) + (1ll << 40);

	//???

	const int hatena = 2;

	rep(i, N / hatena) {

		ll a[hatena];

		rep(j, hatena) a[j] = getint();

		rep(j, 20) {

			rep(k, hatena) kazu[j] += a[k] >> j & m;

		}

	}

	rep(i, N % hatena) {

		ll a = getint();

		rep(j, 20) kazu[j] += a >> j & m;

	}



	ll kotae = 0;

	const ll m2 = (1 << 20) - 1;

	rep(j, 20) {

		ll tmp = (1ll << j) % mod;

		ll tmpk = (kazu[j] & m2);

		tmpk = tmpk * (N - tmpk) % mod;

		kotae += tmp * tmpk % mod;



		tmp = (1ll << (j + 20)) % mod;

		tmpk = (kazu[j] >> 20 & m2);

		tmpk = tmpk * (N - tmpk) % mod;

		kotae += tmp * tmpk % mod;



		tmp = (1ll << (j + 40)) % mod;

		tmpk = (kazu[j] >> 40 & m2);

		tmpk = tmpk * (N - tmpk) % mod;

		kotae += tmp * tmpk % mod;

	}



	printf("%lld", kotae% mod);



	Would you please return 0;

}