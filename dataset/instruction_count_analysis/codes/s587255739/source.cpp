#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



//トライ木って何よ

int T[100001][2];

char D[100001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N;

	ll L;

	scanf("%d", &N);

	scanf("%lld", &L);

	getchar_unlocked();

	int k = 0;

	rep(i, N) {

		int mae = 0;

		ll d = L;

		char c;

		while ((c = getchar_unlocked()) >= '0') {

			int C = c - '0';

			if (!T[mae][C]) {

				T[mae][C] = ++k;

				D[k] = __builtin_ctzll(d);

			}

			mae = T[mae][C];

			d--;

		}

	}

	ll kotae = 0;

	rep1(i, k) {

		kotae ^= 1ll << D[i];

	}



	if (kotae) printf("Alice\n");

	else printf("Bob\n");



	Would you please return 0;

}