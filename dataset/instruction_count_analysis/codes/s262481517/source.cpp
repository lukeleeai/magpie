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

#define Would

#define you

#define please



int P[200002];

bool eranda[200002];



int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), H = getint(), W = getint();



	int R[100000], C[100000], A[100000];

	rep(i, N) {

		R[i] = getint() - 1;

		C[i] = getint() + H - 1;

		A[i] = getint();

	}

	

	int SR[100000], SC[100000], SA[100000];

	int kazu[100001] = {};

	rep(i, N) kazu[A[i]]++;

	for (int i = 99999; i >= 0; i--) kazu[i] += kazu[i + 1];

	rep(i, N) {

		SA[--kazu[A[i]]] = A[i];

		SR[kazu[A[i]]] = R[i];

		SC[kazu[A[i]]] = C[i];

	}



	rep(i, H + W) P[i] = -1;

	ll kotae = 0;

	rep(i, N) {

		int r = Find(SR[i]);

		int c = Find(SC[i]);

		if (r != c) {

			if (!(eranda[r] && eranda[c])) {

				if (P[r] > P[c]) swap(r, c);

				P[r] += P[c];

				eranda[r] |= eranda[c];

				P[c] = r;

				kotae += SA[i];

			}

		}

		else {

			if (eranda[r] == 0) {

				eranda[r] = 1;

				kotae += SA[i];

			}

		}

	}



	printf("%lld", kotae);





	Would you please return 0;

}