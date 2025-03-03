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



const ll mod = 998244353;

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



int kazu[100001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();



	//解けなかった...ｶﾅｼｲ...

	if (getint() != 0) {

		printf("0");

		return 0;

	}



	int saidai = 0;;

	rep(i, N - 1) {

		int d = getint();

		if (!d) {

			printf("0");

			return 0;

		}

		kazu[d]++;

		chmax(saidai, d);

	}



	ll kotae = 1;

	int mae = 1;

	rep1(i, saidai) {

		rep(j, kazu[i]) kotae = kotae * mae % mod;

		mae = kazu[i];

	}



	printf("%d", kotae);



	Would you please return 0;

}