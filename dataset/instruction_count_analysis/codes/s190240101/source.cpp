#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

//#include<algorithm>

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

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

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

	if (X == 0) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

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



int N, M;

int K[100001];

int to[200001], ne[200001], he[100001], num[200001];

int dame[100001];

int S1[200001], S2[200001];



int dfs(int v, int prev) {

	auto s1 = S1 + K[v - 1];

	auto s2 = S2 + K[v - 1];

	int sm = K[v] - K[v - 1];

	if (dame[v]) {

		if (dame[v] >= 2) {

			ll tmp = dfs(to[dame[v]], dame[v] ^ 1);

			int k = sm - num[dame[v]];

			for (int i = k - 1; i < sm; i++) {

				s1[i] = s1[i] * tmp % M;

			}

			s2[k - 1] = tmp;

			tmp = s2[sm - 1];

			for (int i = sm - 2; i >= 0; i--) {

				tmp = tmp * s2[i] % M;

				s2[i] = tmp;

			}

			dame[v] = -1;

		}



		ll ret = 1;

		if (prev >= 2) {

			int k = sm - num[prev];

			if (k >= 2) ret *= s1[k - 2];

			if (k < sm) ret *= s2[k];

			ret %= M;

		}

		else ret = s1[sm - 1];



		return ret + 1;

	}

	dame[v] = prev;

	ll ret = 1;

	int k = 0;

	for (int i = he[v]; i; i = ne[i]) {

		int tmp = 1;

		if (i != prev) {

			tmp = dfs(to[i], i ^ 1);

			ret = ret * tmp % M;

		}

		s1[k] = ret;

		s2[k++] = tmp;

	}

	if (prev == -1) {

		ll tmp2 = s2[sm - 1];

		for (int i = k - 2; i >= 0; i--) {

			tmp2 = tmp2 * s2[i] % M;

			s2[i] = tmp2;

		}

	}

	return ret + 1;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	N = getint();

	M = getint();



	int k = 2;

	rep1(i, N - 1) {

		int x = getint(), y = getint();



		num[k] = K[x]++;

		to[k] = y;

		ne[k] = he[x];

		he[x] = k++;

		num[k] = K[y]++;

		to[k] = x;

		ne[k] = he[y];

		he[y] = k++;

	}

	rep1(i, N) K[i] += K[i - 1];



	rep1(j, N) putint(dfs(j, -1) - 1);



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}