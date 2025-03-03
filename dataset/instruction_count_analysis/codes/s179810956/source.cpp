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



int N;

int E[200001], n[200001], H[100001];

int kyori, kotae;

int dfs(int p, int mae, int d) {

	int kazu = 1;

	if (p == N) {

		kazu += 1 << 20;

		kyori = (d + 1) / 2;

	}

	for (int i = H[p]; i; i = n[i]) if (E[i] != mae) kazu += dfs(E[i], p, d + 1);

	if (kazu > (1 << 20) && d == kyori + 1) kotae = kazu - (1 << 20);

	return kazu;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	N = getint();

	int kari = 1;

	rep(i, N - 1) {

		int a = getint(), b = getint();

		E[kari] = b;

		n[kari] = H[a];

		H[a] = kari++;

		E[kari] = a;

		n[kari] = H[b];

		H[b] = kari++;

	}



	dfs(1, 0, 1);



	if (N - kotae > kotae) printf("Fennec");

	else printf("Snuke");



	Would you please return 0;

}