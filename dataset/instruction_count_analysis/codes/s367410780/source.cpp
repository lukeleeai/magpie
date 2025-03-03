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

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

const int dm = 1 << 20;

char dn[dm], * di = dn;

inline void putint(ll X) {

	if (!X) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

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

void pakuri_sort(int N, int A[]) {

	const int b = 8;

	int tmp[100001];

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

int A[100000];

ll B[100001];

int C[100001];

int MA[100001], MI[100001];

int saidai, k = 1;

ll kotae[100001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int k3 = 0;

	rep(i, N) {

		int a = getint();

		if (a > saidai) {

			MA[k] = a;

			MI[k] = i;

			B[k] += a - saidai;

			C[k++]++;

			saidai = a;

		}

		else A[k3++] = a;

	}

	if (k < 10) {

		rep(i, k3) {

			int k2 = 1;

			while (MA[k2] < A[i]) k2++;

			B[k2] += A[i] - MA[k2 - 1];

			C[k2]++;

		}

	}

	else {

		pakuri_sort(k3, A);

		int k2 = 1;

		rep(i, k3) {

			while (MA[k2] < A[i]) k2++;

			B[k2] += A[i] - MA[k2 - 1];

			C[k2]++;

		}

	}



	ll cnt = 0;

	for (int i = k - 1; i >= 1; i--) {

		kotae[MI[i]] = B[i] + (MA[i] - MA[i - 1]) * cnt;

		cnt += C[i];

	}



	rep(i, N) putint(kotae[i]);



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}