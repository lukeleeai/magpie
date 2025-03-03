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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	if (N == 1) {

		printf("YES\n");

		return 0;

	}



	int saisho = getint();

	ll goukei = saisho;



	int saidai = 0;

	int mae = saisho;

	int tugi = getint();

	goukei += tugi;

	int sa = tugi - mae;

	chmax(saidai, sa);

	int amari = sa % N;

	mae = tugi;

	rep1(i, N - 2) {

		tugi = getint();

		goukei += tugi;

		sa = tugi - mae;

		chmax(saidai, sa);

		if ((sa - amari) % N) {

			printf("NO\n");

			return 0;

		}

		mae = tugi;

	}

	sa = saisho - mae;

	chmax(saidai, sa);

	if ((sa - amari) % N) {

		printf("NO\n");

		return 0;

	}

	

	ll n = ll(N) * (N + 1) / 2;

	if (goukei % n) {

		printf("NO\n");

		return 0;

	}

	int k = goukei / n;

	if (saidai > k) { 

		printf("NO\n");

		return 0;

	}

	if ((amari - k) % N) {

		printf("NO\n");

		return 0;

	}



	printf("YES\n");





	Would you please return 0;

}