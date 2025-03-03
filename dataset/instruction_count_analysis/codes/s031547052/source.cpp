#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

//#include<vector>

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





	int N = getint();

	int A[300][300];

	bool owari = 0;

	rep(i, N) rep(j, N) A[i][j] = getint();

	rep(i, N) A[i][i] = 1e9;



	ll kotae = 0;

	rep(i, N) {

		rep(j, i) {

			auto a = A[i] + j;

			auto b = A[i];

			auto c = A[j];

			bool B = 1;

			rep(k, N) {

				if (*a == b[k] + c[k]) B = 0;

				if (*a > b[k] + c[k]) {

					printf("-1");

					return 0;

				}

			}

			if (B) kotae += *a;

		}

	}



	printf("%lld", kotae);



	Would you please return 0;

}