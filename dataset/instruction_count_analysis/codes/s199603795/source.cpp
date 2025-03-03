//#include"stdc++.h"

#include<cstdio>

#include<cmath>

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

#define Would

#define you

#define please



int N, K;

int A[500];

inline bool keisan(int k) {

	int a[500];

	int ouchaku = 0;

	rep(j, N) {

		a[j] = A[j] % k;

		ouchaku += min(a[j], k - a[j]);

		if (ouchaku > K + K) return false;

	}

	sort(a, a + N);

	int x = 0, y = N - 1;

	int tmp = a[0] + a[N - 1] - k;

	int kazu = a[0] + k - a[N - 1];

	while (x + 1 < y) {

		if (tmp <= 0) {

			tmp += a[++x];

			kazu += a[x];

		}

		else {

			tmp += a[--y] - k;

			kazu += k - a[y];

		}

	}

	if (kazu / 2 <= K) {

		printf("%d", k);

		return true;

	}

	return false;

}



const int cm = 1 << 12;

char cn[cm], * ci = cn, ct;

inline int getint() {

	int A = 0;

	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread_unlocked(cn, 1, cm, stdin);



	N = getint();

	K = getint();

	int goukei = 0;

	rep(i, N) {

		A[i] = getint();

		goukei += A[i];

	}



	int yakusuu[15000];

	int M = 0;

	int sq = sqrt(goukei);

	rep1(i, sq) {

		if (goukei % i == 0) {

			yakusuu[M++] = i;

			if (i * i != goukei) {

				if (keisan(goukei / i)) return 0;

			}

		}

	}



	for (int i = M - 1; i >= 0; i--) {

		if (keisan(yakusuu[i])) return 0;

	}



	Would you please return 0;

}