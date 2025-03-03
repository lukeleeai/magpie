#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	int pn = 1;

	if (ci - cn + 16 > cm) {

		if ((ct = getcha()) == '-') { pn = -1; ct = getcha(); }

		A = ct - '0';

		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

	else {

		if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }

		A = ct - '0';

		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

}



const ll mod = 1e9 + 7;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	ll kotae1 = 0;

	int mae = getint();

	rep1(i, N - 1) {

		ll tugi = getint();

		kotae1 += (tugi - mae) * i * (N - i)  % mod;

		mae = tugi;

	}

	kotae1 %= mod;



	ll kotae2 = 0;

	mae = getint();

	rep1(i, M - 1) {

		ll tugi = getint();

		kotae2 += (tugi - mae) * i * (M - i) % mod;

		mae = tugi;

	}

	kotae2 %= mod;



	printf("%lld", kotae1 * kotae2 % mod);



	Would you please return 0;

}