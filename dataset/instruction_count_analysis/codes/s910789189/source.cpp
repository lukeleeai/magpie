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



int memo[100001];

int to[100001], ne[100001], he[100001];

int dfs(int A) {

	if (memo[A] != -1) return memo[A];

	int saidai = 0;

	for (int i = he[A]; i; i = ne[i]) {

		chmax(saidai, dfs(to[i]));

	}

	return memo[A] = saidai + 1;

}



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





	int N = getint(), M = getint();

	rep1(i, M) {

		int x = getint();

		to[i] = getint();

		ne[i] = he[x];

		he[x] = i;

	}



	rep1(i, N) memo[i] = -1;



	int saidai = 0;

	rep1(i, N) if (memo[i] == -1) chmax(saidai, dfs(i) - 1);

	printf("%d", saidai);



	Would you please return 0;

}