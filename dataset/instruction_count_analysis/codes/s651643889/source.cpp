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

	*di++ = '\n';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, A, B;

	scanf("%d", &N);

	scanf("%d", &A);

	scanf("%d", &B);



	ll saidai = (ll)A * B;

	int saishou = A + B - 1;

	if (N < saishou || N > saidai) {

		printf("-1");

		return 0;

	}



	int n = N;

	rep1(i, A) {

		putint(n - A + i);

	}

	n -= A;

	if (B > 1) {

		int dv = (N - A) / (B - 1);

		int rd = (N - A) % (B - 1);

		rep(i, B - 1) {

			int k = dv + (i < rd);

			rep1(j, k) {

				putint(n - k + j);

			}

			n -= k;

		}

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}