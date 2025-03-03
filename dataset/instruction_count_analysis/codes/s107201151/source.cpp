#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include<cstdio>

#include<algorithm>

#include<functional>

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



const int cm = 1 << 14;

char cn[cm], * ci = cn, ct;

inline int getint() {

	int A = 0;

	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



const int mod = 1e9 + 7;

int A[1001], B[1001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, cm, stdin);



	int N = getint(), M = getint();

	rep(i, N) A[i] = getint();

	rep(i, M) B[i] = getint();

	sort(A, A + N, greater<int>());

	sort(B, B + M, greater<int>());



	int Aima = 0;

	int Bima = 0;

	ll kotae = 1;

	int nokori = 0;



	for (int i = N * M; i >= 1; i--) {

		if (A[Aima] == i && B[Bima] == i) {

			nokori += Aima++ + Bima++;

		}

		else if (A[Aima] == i) {

			kotae = kotae * Bima % mod;

			nokori += Bima - 1;

			Aima++;

		}

		else if (B[Bima] == i) {

			kotae = kotae * Aima % mod;

			nokori += Aima - 1;

			Bima++;

		}

		else {

			kotae = kotae * nokori-- % mod;

		}

	}



	printf("%lld", kotae);



	Would you please return 0;

}