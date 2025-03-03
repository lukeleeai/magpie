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

inline ll getint() {

	ll A = 0;

	if (ci - cn + 24 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	ll a[100000];

	ll goukei = 0;

	rep(i, N) {

		a[i] = getint();;

		goukei ^= a[i];

	}



	int M = 60;

	int r = 0;

	for (int i = M - 1; i >= 0; i--) {

		if (!(goukei >> i & 1)) {

			for (int j = r; j < N; j++) {

				if (a[j] >> i & 1) {

					swap(a[r], a[j]);

					for (int k = max(j, r + 1); k < N; k++) {

						if (a[k] >> i & 1) {

							a[k] ^= a[r];

						}

					}

					if (!(a[0] >> i & 1)) {

						a[0] ^= a[r];

					}

					r++;

					break;

				}

			}

		}

	}



	printf("%lld", a[0] + (a[0] ^ goukei));



	Would you please return 0;

}