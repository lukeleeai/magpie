#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<iostream>

#include<algorithm>

#include<cstring>

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





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), K = getint();



	int A[200200];

	rep(i, N) A[i] = getint();

	ll owa = ll(N) * N;



	rep(p, K) {

		int B[400200] = {};

		rep(i, N) {

			B[max(0, i - A[i])]++;

			B[i + A[i] + 1]--;

		}

		ll kei = B[0];

		A[0] = B[0];

		rep1(i, N - 1) {

			kei +=(A[i] = A[i - 1] + B[i]);

		}

		if (kei == owa) break;

	}



	rep(i, N) cosp(A[i]);



	Would you please return 0;

}