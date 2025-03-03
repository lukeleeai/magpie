#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<bitset>

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



int N, M;

bool A[700][700];

int D[700];

bool dame;

int dfs(int v, int d) {

	if (dame) return 0;

	D[v] = d;

	int ret = (d & 2) - 1;

	auto a = A[v];

	for (int to = 0; to < N; to++) if (!a[to]) {

		if (!D[to]) ret += dfs(to, d ^ 2);

		else if (D[to] == d) {

			dame = 1;

			return 0;

		}

	}

	return ret;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	N = getint();

	M = getint();

	rep(i, M) {

		int a = getint() - 1, b = getint() - 1;

		A[a][b] = true;

		A[b][a] = true;

	}

	rep(i, N) A[i][i] = true;



	int kouho[700];

	int k = 0;

	int mannnaka = 0;

	rep(i, N) if (!D[i]) {

		int tmp = abs(dfs(i, 1));

		if (dame) {

			printf("-1");

			return 0;

		}

		mannnaka += tmp;

		kouho[k++] = tmp;

	}





	bitset<710> BS(0);

	BS[0] = 1;

	rep(i, k) BS |= BS << kouho[i];



	int saishou = 1e9;

	for (int i = 0; i <= mannnaka; i++) {

		if (BS[i]) chmin(saishou, abs(i * 2 - mannnaka));

	}

	int X = (N + saishou) / 2;

	int Y = (N - saishou) / 2;

	int kotae = X * (X - 1) / 2 + Y * (Y - 1) / 2;



	printf("%d", kotae);



	Would you please return 0;

}