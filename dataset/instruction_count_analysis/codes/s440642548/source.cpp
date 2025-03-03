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

const int dm = 1 << 21;

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

	*di++ = ' ';

}



int N;

int E[400001], ne[400001], he[200001], cnt[2];

bool D[200001], d;

void dfs(int p, int prev) {

	D[p] = d;

	cnt[d]++;



	d = !d;

	for (int i = he[p]; i; i = ne[i]) {

		int to = E[i];

		if (to != prev) {

			dfs(to, p);

		}

	}

	d = !d;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	N = getint();

	int k = 1;

	rep(i, N - 1) {

		int a = getint(), b = getint();

		E[k] = b;

		ne[k] = he[a];

		he[a] = k++;

		E[k] = a;

		ne[k] = he[b];

		he[b] = k++;

	}



	dfs(1, 0);



	int k0 = 0, k1 = 0, k2 = 0;

	int n0 = (N + 2) / 3;

	int n1 = (N + 1) / 3;

	int n2 = N / 3;



	if (cnt[0] < cnt[1]) {

		if (cnt[0] > N / 3) {

			rep1(i, N) {

				if (D[i] == 0) {

					if (k0 < n0) putint(k0++ * 3 + 1);

					else putint(k2++ * 3 + 3);

				}

				else {

					if (k1 < n1) putint(k1++ * 3 + 2);

					else putint(k2++ * 3 + 3);

				}

			}

		}

		else {

			rep1(i, N) {

				if (D[i] == 0) {

					putint(k2++ * 3 + 3);

				}

				else {

					if (k0 < n0) putint(k0++ * 3 + 1);

					else if (k1 < n1) putint(k1++ * 3 + 2);

					else putint(k2++ * 3 + 3);

				}

			}

		}

	}

	else {

		if (cnt[1] > N / 3) {

			rep1(i, N) {

				if (D[i] == 0) {

					if (k0 < n0) putint(k0++ * 3 + 1);

					else putint(k2++ * 3 + 3);

				}

				else {

					if (k1 < n1) putint(k1++ * 3 + 2);

					else putint(k2++ * 3 + 3);

				}

			}

		}

		else {

			rep1(i, N) {

				if (D[i] == 1) {

					putint(k2++ * 3 + 3);

				}

				else {

					if (k0 < n0) putint(k0++ * 3 + 1);

					else if (k1 < n1) putint(k1++ * 3 + 2);

					else putint(k2++ * 3 + 3);

				}

			}

		}

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}