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



//よくわかんなくなってきた

const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline ll getint() {

	ll A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	ll N = getint(), M = getint();

	int A[100002] = {};

	rep(i, N) A[getint()]++;	

	for (int i = 100000; i > 1; i--) {

		A[i - 1] += A[i];

	}



	int L = 0;

	int R = 200001;

	while (L + 1 < R) {

		int m = (L + R) / 2;



		ll kazu = 0;

		for (int i = 100000; i >= 1; i--) {

			ll k = A[i] - A[i + 1];

			if (k) {

				int k2 = m - i;

				if (k2 <= 1) kazu += N * k;

				else if (k2 <= 100000) kazu += A[k2] * k;

			}

		}



		if (kazu >= M) L = m;

		else R = m;

	}



	ll S[100002];

	S[100001] = 0;

	for (int i = 100000; i >= 1; i--) {

		S[i] = S[i + 1] + ll(A[i] - A[i + 1]) * i;

	}

	ll kotae = 0;

	ll kazu = 0;

	for (int i = 100000; i >= 1; i--) {

		ll k = A[i] - A[i + 1];

		if (k) {

			int k2 = L - i;

			if (k2 <= 1) {

				kotae += S[1] * k;

				kotae += N * k * i;

				kazu += N * k;

			}

			else if (k2 <= 100000) {

				kotae += S[k2] * k;

				kotae += A[k2] * k * i;

				kazu += A[k2] * k;

			}

		}

	}



	kotae -= ll(kazu - M) * L;



	printf("%lld", kotae);





	Would you please return 0;

}