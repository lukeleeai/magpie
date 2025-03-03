#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



ll V[51];

int to[102], ne[102], he[51];

void dfs(int p, ll v, int mae) {

	V[p] = v >> 1;

	for (int q = he[p]; q; q = ne[q]) {

		int To = to[q];

		if (mae != To) {

			v ^= 1ll << (q >> 1);

			dfs(To, v, p);

			v ^= 1ll << (q >> 1);

		}

	}

}



//包除原理でもできるらしいのでがんばる

int N, M;

int kazoeru[51];

ll seiyaku[20];

void keisan(int i, bool k, ll are) {

	if (i == M) {

		kazoeru[__builtin_popcountll(are)] += 1 - k * 2;

	}

	else {

		keisan(i + 1, k, are);

		keisan(i + 1, !k, are | seiyaku[i]);

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	scanf("%d", &N);

	int kari = 2;

	rep(i, N - 1) {

		int a, b;

		scanf("%d %d", &a, &b);

		to[kari] = b;

		ne[kari] = he[a];

		he[a] = kari++;

		to[kari] = a;

		ne[kari] = he[b];

		he[b] = kari++;

	}



	dfs(1, 0, 0);



	scanf("%d", &M);

	rep(i, M) {

		int u, v;

		scanf("%d %d", &u, &v);

		seiyaku[i] = V[u] ^ V[v];

	}



	keisan(0, 1, 0);



	ll kotae = 0;

	rep1(i, N) {

		ll tmp = (1ll << N - 1) - (1ll << (N - i - 1));

		kotae += tmp * kazoeru[i];

	}

	printf("%lld", kotae);



	Would you please return 0;

}