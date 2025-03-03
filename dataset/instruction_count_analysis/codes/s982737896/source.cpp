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



const int dm = 1 << 22;

char dn[dm], * di = dn;

inline void putint(ll X, ll X2) {

	if (X == 0) {

		*di++ = '0';

	}

	else {

		if (X < 0) {

			*di++ = '-';

			X = -X;

		}

		int keta = 0;

		char C[20];

		while (X) {

			*(C + keta) = '0' + X % 10;

			X /= 10;

			keta++;

		}

		for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	}

	*di++ = ' ';

	if (X2 == 0) {

		*di++ = '0';

	}

	else {

		if (X2 < 0) {

			*di++ = '-';

			X2 = -X2;

		}

		int keta = 0;

		char C[20];

		while (X2) {

			*(C + keta) = '0' + X2 % 10;

			X2 /= 10;

			keta++;

		}

		for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	}

	*di++ = '\n';

}



ll tmp[200010];

void pakuri_sort(int N, ll A[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) {

			tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		}

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) {

			A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

		}

	}

}



int kueri[200010], D[200010];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int Q = getint();

	int k = 1;

	int B[200010];

	ll A[200010];

	rep(i, Q) {

		if (getcha() == '1') {

			getcha();

			A[k] = getint() + (1 << 30) + (ll(k) << 32);

			B[k] = getint();

			k++;

		}

		else {

			getcha();

			kueri[k]++;

		}

	}



	pakuri_sort(k - 1, A + 1);

	int T[200010];

	rep1(i, k - 1) T[A[i] >> 32] = i;



	if (k & 1) {

		tmp[k] = k / 2 + ((ll)(k / 2 + 1) << 32);

	}

	else {

		tmp[k] = k / 2;

	}



	for (int i = k - 1; i >= 1; i--) {



		int j = T[i];

		int mae = D[j - 1];

		if (!mae) mae = j;

		int ato = D[j + 1];

		if (!ato) ato = j;



		int t = tmp[i + 1] & (1 << 30) - 1;



		if (i & 1) {

			if (j == t) {

				tmp[i] = mae - 1 + ((ll)(ato + 1) << 32);

			}

			else if (j < t) {

				int ato2 = D[t + 1];

				if (!ato2) ato2 = t;

				tmp[i] = t + ((ll)(ato2 + 1) << 32);

			}

			else {

				int mae2 = D[t - 1];

				if (!mae2) mae2 = t;

				tmp[i] = mae2 - 1 + ((ll)t << 32);

			}

		}

		else {

			if (j <= t) tmp[i] = tmp[i + 1] >> 32;

			else tmp[i] = t;

		}



		D[mae] = ato;

		D[ato] = mae;

	}



	rep1(i, k - 1) A[i] = (A[i] & (1ll << 31) - 1) - (1 << 30);



	ll X = 0;

	rep1(i, k - 1) {



		int t = tmp[i] & (1 << 30) - 1;

		int t2 = tmp[i] >> 32;

		int ti = T[i];



		if (i & 1) {

			if (ti < t) X += A[t] - A[ti];

			else if (ti > t2) X += A[ti] - A[t2];

			X += B[i];

		}

		else {

			X += abs(A[ti] - A[t]);

			X += B[i];

		}



		rep(j, kueri[i + 1]) putint(A[tmp[i + 1] & (1 << 30) - 1], X);

	}



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}