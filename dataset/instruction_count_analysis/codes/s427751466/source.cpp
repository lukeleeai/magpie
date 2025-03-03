//ここで手段を選ばないゲスな精神が？



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





	int N = getint();



	short A[1001][1000];

	rep1(i, N) {

		rep(j, N - 1) A[i][j] = getint();

		A[i][N - 1] = 0;

	}

	short* k[1001];

	rep1(i, N) k[i] = A[i];

	int k2[1001] = {};

	k2[0] = 1e9;

	int V[2][1001], kazu = N;

	rep1(i, N) V[0][i] = i;



	int kotae = 0;

	while (kazu && kotae < 80000) {

		kotae++;

		int dotti = kotae & 1;

		int kari = 0;

		rep (i, kazu) {

			int v = V[!dotti][i];

			if (k2[v] < kotae) {

				int a = *k[v];

				if (k2[a] < kotae && *k[a] == v) {

					V[dotti][kari++] = v;

					k[v]++;

					k2[v] = kotae;

					V[dotti][kari++] = a;

					k[a]++;

					k2[a] = kotae;

				}

			}

		}

		kazu = kari;

	}



	int OK = 1;

	rep1(i, N) if (k[i] - A[i] != N - 1) OK = 0;

	if (kotae == 80000) printf("%d", N* (N - 1) / 2);

	else if (!OK) printf("-1"); 

	else printf("%d", kotae - 1);



	Would you please return 0;

}