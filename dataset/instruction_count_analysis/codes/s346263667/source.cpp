#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<vector>

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



const int dm = 1 << 20;

char dn[dm], * di = dn;

inline void putint(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int to[200001], ne[200001], he[100001], saidai, saidaiv;

void dfs1(int v, int mae, int d) {

	if (saidai < d) {

		saidai = d;

		saidaiv = v;

	}

	for (int i = he[v]; i; i = ne[i]) {

		if (to[i] != mae) dfs1(to[i], v, d + 1);

	}

}



vector<int> kazu;

bool dfs2(int v, int mae) {

	bool ret = (saidaiv == v);

	int cnt = 0;

	for (int i = he[v]; i; i = ne[i]) {

		if (to[i] != mae) {

			ret |= dfs2(to[i], v);

			cnt++;

		}

	}

	if (ret) kazu.pb(cnt);

	return ret;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int k = 1;

	rep(i, N - 1) {

		int u = getint(), v = getint();

		to[k] = v;

		ne[k] = he[u];

		he[u] = k++;

		to[k] = u;

		ne[k] = he[v];

		he[v] = k++;

	}



	dfs1(1, 0, 0);

	int tmp = saidaiv;

	saidai = 0;

	dfs1(tmp, 0, 0);



	dfs2(tmp, 0);



	int s = kazu.size() / 2 - 1;

	int n = kazu.size();



	bool gyaku = 0;

	rep1(i, s) {

		if (kazu[i] > kazu[n - i - 1]) {

			gyaku = 1;

			break;

		}

		else if (kazu[i] < kazu[n - i - 1]) {

			break;

		}

	}



	k = 2;

	putint(1);

	if (gyaku) {

		for (int i = n - 2; i >= 1; i--) {

			rep1(j, kazu[i] - 1) putint(k + j);

			putint(k);

			k += kazu[i];

		}

	}

	else {

		rep1(i, n - 2) {

			rep1(j, kazu[i] - 1) putint(k + j);

			putint(k);

			k += kazu[i];

		}

	}

	putint(N);



	if (k != N) {

		printf("-1");

	}

	else {

		fwrite(dn, 1, di - dn, stdout);

	}



	Would you please return 0;

}