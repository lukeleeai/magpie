#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<vector>

#include<cmath>

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

char cn[cm], * ci = cn, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}



int main() {

	fread(cn, 1, cm, stdin);

	int N = 0;

	while ((ct = *ci++) >= '0') N = N * 10 + ct - '0';



	int fu = 0;

	int saishou = 1e9;

	ll goukei = 0;

	rep(i, N) {

		if (ci - cn + 16 > cm) {

			if ((ct = getcha()) == '-') { fu ^= 1; ct = getcha(); }

			int A = ct - '0';

			while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

			goukei += A;

			chmin(saishou, A);

		}

		else {

			if ((ct = *ci++) == '-') { fu ^= 1; ct = *ci++; }

			int A = ct - '0';

			while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

			goukei += A;

			chmin(saishou, A);

		}

	}



	if (fu) goukei -= saishou * 2;



	printf("%lld", goukei);



	Would you please return 0;

}