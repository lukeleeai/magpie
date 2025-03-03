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



int N;

int to[200001], ne[200001], he[100001];

const ll mod = 1e9 + 7;

pair<ll, ll> dfs(int A, int prev) {

	ll kuro = 1;

	ll siro = 1;

	for (int i = he[A]; i; i = ne[i]) {

		int To = to[i];

		if (To != prev) {

			auto k = dfs(To, A);

			kuro = (kuro * k.second) % mod;

			siro = (siro * k.first) % mod;

		}

	}

	return mp(kuro + siro, siro);

}



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





	N = getint();

	int k = 1;

	rep(i, N - 1) {

		int x = getint(), y = getint();

		to[k] = y;

		ne[k] = he[x];

		he[x] = k++;

		to[k] = x;

		ne[k] = he[y];

		he[y] = k++;

	}



	auto M = dfs(1, 0);

	printf("%lld", M.first % mod);



	Would you please return 0;

}