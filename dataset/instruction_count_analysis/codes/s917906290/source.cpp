#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<iostream>

#include<algorithm>

#include<cstring>

#include<queue>

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

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

const int dm = 1 << 21;

char dn[dm], * di = dn;

inline void putint2(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}

inline void putint(ll X) {

	int keta = 0;

	char C[20];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}

void pakuri_sort(int N, ll A[]) {

	const int b = 8;

	ll tmp[200001];

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



	ll LR[200000];

	int T = getint();

	rep(t, T) {

		int N = getint();



		if (N <= 2) {

			int k = getint(), l = getint(), r = getint();

			if (N == 1) putint2(l);

			else if (k == 2) {

				int k2 = getint(), l2 = getint(), r2 = getint();

				if (k2 == 2) putint2(l + l2);

				else putint2(l + max(l2, r2));

			}

			else {

				int k2 = getint(), l2 = getint(), r2 = getint();

				if (k2 == 2) putint2(l2 + max(l, r));

				else putint2(max(l + r2, l2 + r));

			}

			continue;

		}



		ll saishou = 0;

		int k1 = 0, k2 = N;

		rep(i, N) {

			ll k = getint(), l = getint(), r = getint();



			if (l < r) {

				LR[--k2] = (r - l << 32) + k + 1;

				saishou += l;

			}

			else {

				LR[k1++] = (l - r << 32) + k;

				saishou += r;

			}

		}

		pakuri_sort(k1, LR);

		pakuri_sort(N - k1, LR + k1);



		priority_queue<int> PQ;

		int i = k1;

		const ll ma = (1ll << 32) - 1;

		while (i < N && (LR[i] & ma) < k1) {

			PQ.push(LR[i++] >> 32);

		}

		for (int j = k1; j <= N; j++) {

			while (i < N && (LR[i] & ma) <= j) {

				PQ.push(LR[i++] >> 32);

			}

			if (PQ.size()) {

				auto q = PQ.top();

				PQ.pop();

				saishou += q;

			}

		}

		PQ = priority_queue<int>();

		i = k1 - 1;

		while (i >= 0 && (LR[i] & ma) > k1) {

			PQ.push(LR[i--] >> 32);

		}

		for (int j = k1 - 1; j >= 0; j--) {

			while (i >= 0 && (LR[i] & ma) > j) {

				PQ.push(LR[i--] >> 32);

			}

			if (PQ.size()) {

				auto q = PQ.top();

				PQ.pop();

				saishou += q;

			}

		}

		putint(saishou);

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}